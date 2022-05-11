#include "SelectionPile.h"

#include "CardItem.h"
#include "CardPileItem.h"
#include "TableauPile.h"

#include <QList>

#include <iostream>
#include <vector>

SelectionPile::SelectionPile(MainWindow* window, TableauPile& original)
  : GameItem{window}, m_original{original}
{
  setFlag(GraphicsItemFlag::ItemIsMovable);
}

bool SelectionPile::accepts(const Card& card)
{
  return true;
}

QRectF SelectionPile::boundingRect() const
{
  // TODO: Come up with a way to take away this code redundancy.
  qreal height;

  if(isEmpty()) {
    height = CardItem::HEIGHT;
  } else {
    height = (count() - 1) * CardPileItem::PADDING + CardItem::HEIGHT;
  }

  return QRectF{0, 0, CardItem::WIDTH, height};
}

void SelectionPile::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
  // TODO: Remove this redundancy too.
  painter->setPen(CardItem::BLACK_PEN);
  painter->drawRect(boundingRect());

  if(!isEmpty()) {
    for(size_t i = 0; i < count() - 1; i++) {
      Card card = cards().at(i);
      int y = CardPileItem::PADDING * i;

      if(card.isFlipped()) {
        painter->setPen(card.isBlack() ? CardItem::BLACK_PEN : CardItem::RED_PEN);
        painter->drawRect(0, y, CardItem::WIDTH, CardPileItem::PADDING);

        QStaticText text{CardItem::RANKS[card.getRank()]};
        painter->drawStaticText(2, y, text);
      } else {
        painter->fillRect(0, y, CardItem::WIDTH, CardPileItem::PADDING, CardItem::BACK);
        painter->drawRect(0, y, CardItem::WIDTH, CardPileItem::PADDING);
      }
    }

    Card card = top();
    int y = CardPileItem::PADDING * (count() - 1);

    if(card.isFlipped()) {
      QStaticText text{CardItem::RANKS[card.getRank()]};
      auto textSize = text.size();
      painter->setPen(card.isBlack() ? CardItem::BLACK_PEN : CardItem::RED_PEN);
      painter->fillRect(0, y, CardItem::WIDTH, CardItem::HEIGHT, QBrush{Qt::white});
      painter->drawRect(0, y, CardItem::WIDTH, CardItem::HEIGHT);
      painter->drawStaticText(2, y, text);
      painter->drawStaticText(CardItem::WIDTH - textSize.width(), y + (CardItem::HEIGHT - textSize.height()), text);
    } else {
      painter->fillRect(0, y, CardItem::WIDTH, CardItem::HEIGHT, CardItem::BACK);
      painter->drawRect(0, y, CardItem::WIDTH, CardItem::HEIGHT);
    }
  }
}

void SelectionPile::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
  QDrag *drag = new QDrag(event->widget());
  QMimeData *mime = new QMimeData;

  QList<Card> cardList{};

  for(Card card : cards()) {
    cardList.append(card);
  }

  mime->setProperty("cards", qVariantFromValue(cardList));
  drag->setMimeData(mime);

  QPixmap pixmap(boundingRect().width(), boundingRect().height());
  pixmap.fill(Qt::white);

  QPainter painter(&pixmap);
  painter.setRenderHint(QPainter::Antialiasing);
  paint(&painter, 0, 0);
  painter.end();

  drag->setPixmap(pixmap);
  drag->setHotSpot(event->pos().toPoint());

  Qt::DropAction action = drag->exec();

  if(action == Qt::IgnoreAction) {
    for(Card card : cards()) {
      m_original.add(card, false);
    }
  }

  scene()->removeItem(this);
}
