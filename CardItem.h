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
  /**
   * @brief RANKS the string representations of all of the possible ranks.
   */
  static QString RANKS[];

  /**
   * @brief SUITS the string representations of all of the possible suits.
   */
  static QString SUITS[];

  /**
   * @brief BACK a constant brush used for painting the backs of the cards.
   */
  static QBrush BACK;

  /**
   * @brief RED_PEN a constant red pen.
   */
  static QPen RED_PEN;

  /**
   * @brief BLACK_PEN a constant black pen.
   */
  static QPen BLACK_PEN;

  /**
   * @brief WIDTH the width of each card.
   */
  static const int WIDTH = 70;

  /**
   * @brief HEIGHT the height of each card.
   */
  static const int HEIGHT = 100;

  /**
   * @brief CardItem constructs a new CardItem for the specified window that represents the specified card.
   * @param window the window to add the card to
   * @param card the card to be represented
   */
  CardItem(MainWindow* window, Card card);

  /**
   * @brief boundingRect calculates the bounding rectangle for this card.
   * @return the bounding rectangle for this card.
   */
  QRectF boundingRect() const;

  /**
   * @brief paint paints the graphical representation of the Card onto the window.
   * @param painter the painter to use to paint
   * @param option
   * @param widget
   *
   * @see QGraphicsItem::paint(QPainter*, const QStyleOptionGraphicsItem, QWidget)
   */
  void paint(QPainter *painter,
             const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  /**
   * @brief getCard returns the card that this item represents.
   * @return the card that this item represents.
   */
  Card getCard();

  /**
   * @brief draw the specified card on to the specified painter at the specified location.
   * @param painter the painter to use to draw the card.
   * @param card the card to be drawn.
   * @param x the x location of the card.
   * @param y the y location of the card.
   */
  static void draw(QPainter* painter, Card& card, qreal x, qreal y);

protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

private:
  Card m_card;
};

#endif // CARDITEM_H
