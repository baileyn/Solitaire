#ifndef CARDPILEITEM_H
#define CARDPILEITEM_H

#include "GameItem.h"
#include "TableauPile.h"
#include <QGraphicsItem>

class CardPileItem : public GameItem
{
public:
  const static size_t PADDING = 20;

  CardPileItem(MainWindow* window, CardPile& pile);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  QRectF boundingRect() const;
  size_t mouseClickToCardIndex(QGraphicsSceneMouseEvent* event);

  static void draw(QPainter* painter, CardPile& cardPile);
  static QRectF bounds(const CardPile& cardPile);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event);
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
  void dropEvent(QGraphicsSceneDragDropEvent* event);

private:
  TableauPile m_pile;
};

#endif // CARDPILEITEM_H
