#include "FoundationPileItem.h"

#include "CardItem.h"

#include <QtWidgets>
#include <iostream>

FoundationPileItem::FoundationPileItem(MainWindow* window, FoundationPile& pile)
  : GameItem{window}, m_pile{pile}
{
  setAcceptDrops(true);
}

QRectF FoundationPileItem::boundingRect() const
{
  return QRectF{0, 0, CardItem::WIDTH, CardItem::HEIGHT};
}

void FoundationPileItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
  if(m_pile.isEmpty()) {
    painter->setPen(CardItem::BLACK_PEN);
    painter->drawRect(boundingRect());
  } else {
    CardItem::draw(painter, m_pile.getTop(), 0, 0);
  }
}

void FoundationPileItem::dropEvent(QGraphicsSceneDragDropEvent* event)
{
  QList<Card> cards = *(QList<Card>*)event->mimeData()->property("cards").data();

  if(cards.size() > 1) {
    event->setAccepted(false);
  } else if(m_pile.add(cards.first())) {
    update();
    event->setAccepted(true);
  } else {
    event->setAccepted(false);
  }
}
