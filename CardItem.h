#ifndef CARDITEM_H
#define CARDITEM_H

#include "Card.h"
#include "GameItem.h"

#include <QBrush>
#include <QGraphicsItem>
#include <QPen>

class CardItem : public GameItem
{
public:
  static QString RANKS[];
  static QString SUITS[];
  static QBrush BACK;
  static QPen RED_PEN;
  static QPen BLACK_PEN;

  static const int WIDTH = 70;
  static const int HEIGHT = 100;

  CardItem(MainWindow* window, Card card);

  QRectF boundingRect() const;
  void paint(QPainter *painter,
             const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  /**
   * @brief getCard returns the card that this item represents.
   * @return the card that this item represents.
   */
  Card getCard();

  static void draw(QPainter* painter, Card& card, qreal x, qreal y);

protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

private:
  Card m_card;
};

#endif // CARDITEM_H
