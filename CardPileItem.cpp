#include "CardPileItem.h"

#include "Card.h"
#include "CardItem.h"
#include "MainWindow.h"

#include <QtWidgets>

#include <algorithm>
#include <iostream>

CardPileItem::CardPileItem(MainWindow* window, CardPile& pile)
  : GameItem{window}, m_pile{pile}
{
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
  QPointF origin = pos();

  std::cout << cardIdx << std::endl;

  scene()->addRect(origin.x(), origin.y(), CardItem::WIDTH, cardIdx * PADDING);
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
