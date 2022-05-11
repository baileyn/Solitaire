#include "CardPileItem.h"

#include "Card.h"
#include "CardItem.h"
#include "SelectionPile.h"
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
  draw(painter, m_pile);
}

QRectF CardPileItem::boundingRect() const
{
  return bounds(m_pile);
}

size_t CardPileItem::mouseClickToCardIndex(QGraphicsSceneMouseEvent* event)
{
  return std::min(static_cast<size_t>(event->pos().y() / PADDING), m_pile.count() - 1);
}

void CardPileItem::draw(QPainter* painter, CardPile& cardPile)
{
  painter->drawRect(bounds(cardPile));

  if(!cardPile.isEmpty()) {
    for(size_t i = 0; i < cardPile.count() - 1; i++) {
      Card card = cardPile.cards().at(i);
      int y = PADDING * i;

      if(card.isFlipped()) {
        painter->fillRect(0, y, CardItem::WIDTH, PADDING, QBrush{Qt::white});
        painter->setPen(card.isBlack() ? CardItem::BLACK_PEN : CardItem::RED_PEN);
        painter->drawRect(0, y, CardItem::WIDTH, PADDING);

        QStaticText text{CardItem::RANKS[card.getRank()] + CardItem::SUITS[card.getSuit()]};
        painter->drawStaticText(2, y, text);
      } else {
        painter->fillRect(0, y, CardItem::WIDTH, PADDING, CardItem::BACK);
        painter->drawRect(0, y, CardItem::WIDTH, PADDING);
      }
    }

    Card card = cardPile.top();
    int y = PADDING * (cardPile.count() - 1);

    CardItem::draw(painter, card, 0, y);
  }
}

QRectF CardPileItem::bounds(const CardPile& cardPile)
{
  qreal height;

  if(cardPile.isEmpty()) {
    height = CardItem::HEIGHT;
  } else {
    height = (cardPile.count() - 1) * PADDING + CardItem::HEIGHT;
  }

  return QRectF{0, 0, CardItem::WIDTH, height};
}

void CardPileItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  auto cardIdx = mouseClickToCardIndex(event);

  if(m_pile.isEmpty() || !m_pile.cards().at(cardIdx).isFlipped()) {
    event->ignore();
    return;
  }

  QPointF origin = pos();

  SelectionPile* item = new SelectionPile(window(), m_pile);

  for(size_t i = cardIdx; i < m_pile.count(); i++) {
    Card card = m_pile.cards()[i];
    item->cards().push_back(card);
  }

  m_pile.cards().erase(m_pile.cards().begin() + cardIdx, m_pile.cards().end());
  item->moveBy(origin.x(), origin.y() + (cardIdx * PADDING));

  scene()->addItem(item);

  event->setPos(QPointF{event->pos().x(), event->pos().y() - cardIdx * PADDING});
  item->fireMouseMoveEvent(event);
  scene()->update();
}

void CardPileItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
{
  if(!m_pile.top().isFlipped()) {
    m_pile.top().flip();
  } else {
    if(window()->playsOnFoundation(m_pile.top())) {
      m_pile.cards().pop_back();
    }
  }

  scene()->update();
}

void CardPileItem::dropEvent(QGraphicsSceneDragDropEvent* event)
{
  QList<Card> cards = *(QList<Card>*)event->mimeData()->property("cards").data();

  for(Card card : cards) {
    if(m_pile.add(card)) {
      event->setAccepted(true);
    } else {
      event->setAccepted(false);
    }
  }

  update();
}
