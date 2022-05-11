#include "CardPileItem.h"

#include "Card.h"
#include "CardItem.h"
#include "MainWindow.h"

#include <QtWidgets>

#include <algorithm>
#include <iostream>

CardPileItem::CardPileItem(MainWindow* window, CardPile& pile)
  : GameItem{window}
{
  for(auto i : pile.cards()) {
    m_pile.cards().push_back(i);
  }

  setAcceptDrops(true);
}

void CardPileItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
  painter->drawRect(boundingRect());

  if(!m_pile.isEmpty()) {
    for(size_t i = 0; i < m_pile.count() - 1; i++) {
      Card card = m_pile.cards().at(i);
      int y = PADDING * i;

      if(card.isFlipped()) {
        painter->setPen(card.isBlack() ? CardItem::BLACK_PEN : CardItem::RED_PEN);
        painter->drawRect(0, y, CardItem::WIDTH, PADDING);

        QStaticText text{CardItem::RANKS[card.getRank()]};
        painter->drawStaticText(2, y, text);
      } else {
        painter->fillRect(0, y, CardItem::WIDTH, PADDING, CardItem::BACK);
        painter->drawRect(0, y, CardItem::WIDTH, PADDING);
      }
    }

    Card card = m_pile.top();
    int y = PADDING * (m_pile.count() - 1);

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

QRectF CardPileItem::boundingRect() const
{
  qreal height;

  if(m_pile.isEmpty()) {
    height = CardItem::HEIGHT;
  } else {
    height = (m_pile.count() - 1) * PADDING + CardItem::HEIGHT;
  }

  return QRectF{0, 0, CardItem::WIDTH, height};
}

size_t CardPileItem::mouseClickToCardIndex(QGraphicsSceneMouseEvent* event)
{
  return std::min(static_cast<size_t>(event->pos().y() / PADDING), m_pile.count() - 1);
}

void CardPileItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  auto cardIdx = mouseClickToCardIndex(event);

  if(m_pile.isEmpty() || !m_pile.cards().at(cardIdx).isFlipped()) {
    event->ignore();
    return;
  }

  QPointF origin = pos();
  TableauPile selectionPile{};

  auto oldRect = boundingRect();

  for(int i = cardIdx; i < m_pile.count(); i++) {
    Card card = m_pile.cards().back();
    m_pile.cards().pop_back();
    selectionPile.cards().push_front(card);
  }

  CardPileItem* item = new CardPileItem(window(), selectionPile);
  item->moveBy(origin.x(), origin.y() + oldRect.height() - CardItem::HEIGHT);
  scene()->addItem(item);

  scene()->update();
}

void CardPileItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
  if(!m_pile.top().isFlipped()) {
    m_pile.top().flip();
  }

  scene()->update();
}

void CardPileItem::dropEvent(QGraphicsSceneDragDropEvent* event)
{
  Card card = *(Card*)event->mimeData()->property("card").data();

  if(m_pile.add(card)) {
    window()->removeCardItem(card);
    update();
    event->setAccepted(true);
  } else {
    std::cout << "Doesn't play there" << std::endl;
    event->setAccepted(false);
  }
}
