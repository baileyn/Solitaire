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

void FoundationPileItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  QRectF rect = boundingRect();

  if(m_pile.isEmpty()) {
    painter->setPen(CardItem::BLACK_PEN);
    painter->drawRect(boundingRect());
  } else {
    Card card = m_pile.top();
    painter->fillRect(rect, QBrush{Qt::white});
    painter->setPen(card.isBlack() ? CardItem::BLACK_PEN : CardItem::RED_PEN);
    painter->drawRect(rect);

    QStaticText text{CardItem::RANKS[card.getRank()]};
    auto textSize = text.size();
    painter->drawStaticText(0, 0, text);
    painter->drawStaticText(rect.width() - textSize.width(), rect.height() - textSize.height(), text);
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
