#include "CardPileItem.h"

#include "Card.h"
#include "CardItem.h"
#include <QBrush>
#include <QPainter>
#include <QStaticText>

CardPileItem::CardPileItem(CardPile& pile)
  : m_pile{pile}
{

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
