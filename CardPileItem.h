#ifndef CARDPILEITEM_H
#define CARDPILEITEM_H

#include "CardPile.h"
#include "GameItem.h"
#include <QGraphicsItem>

class CardPileItem : public GameItem
{
public:
  const static size_t PADDING = 20;

  CardPileItem(MainWindow* window, CardPile& pile);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  QRectF boundingRect() const;

  size_t mouseClickToCardIndex(QGraphicsSceneMouseEvent* event);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event);
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
  void dropEvent(QGraphicsSceneDragDropEvent* event);

private:
  CardPile m_pile;
};

#endif // CARDPILEITEM_H
