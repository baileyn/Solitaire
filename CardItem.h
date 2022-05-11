#ifndef CARDITEM_H
#define CARDITEM_H

#include "Card.h"

#include <QBrush>
#include <QGraphicsItem>
#include <QPen>

class CardItem : public QGraphicsItem
{
public:
  static QString RANKS[];
  static QBrush BACK;
  static QPen RED_PEN;
  static QPen BLACK_PEN;

  static const int WIDTH = 70;
  static const int HEIGHT = 100;

  CardItem(Card card);

  QRectF boundingRect() const;
  void paint(QPainter *painter,
             const QStyleOptionGraphicsItem *option,
             QWidget *widget);

protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

private:
  Card m_card;
};

#endif // CARDITEM_H
