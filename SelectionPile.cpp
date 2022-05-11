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

bool SelectionPile::accepts(const Card&)
{
  return true;
}

QRectF SelectionPile::boundingRect() const
{
  return CardPileItem::bounds(*this);
}

void SelectionPile::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
  CardPileItem::draw(painter, *this);
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
