#ifndef CARDPILEITEM_H
#define CARDPILEITEM_H

#include "CardPile.h"
#include <QGraphicsItem>

class CardPileItem : public QGraphicsItem
{
public:
  const static size_t PADDING = 20;

  CardPileItem(CardPile& pile);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  QRectF boundingRect() const;

private:
  CardPile& m_pile;
};

#endif // CARDPILEITEM_H
