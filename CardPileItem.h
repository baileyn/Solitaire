#ifndef CARDPILEITEM_H
#define CARDPILEITEM_H

#include "GameItem.h"
#include "TableauPile.h"
#include <QGraphicsItem>

class CardPileItem : public GameItem
{
public:
  /**
   * @brief PADDING the padding to put between piles of cards
   */
  const static size_t PADDING = 20;

  /**
   * @brief CardPileItem constructs a new CardPileItem to be drawn for the specified window.
   * @param window the window to draw the pile on.
   * @param pile the pile to be represented by this CardPileItem.
   */
  CardPileItem(MainWindow* window, CardPile& pile);

  /**
   * @brief paint paints the CardPile with the specified painter.
   * @param painter the painter to be used to paint.
   * @param option
   * @param widget
   */
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

  /**
   * @brief boundingRect returns the bounding rectangle for this CardPileItem.
   * @return the bounding rectangle for this CardPileItem.
   */
  QRectF boundingRect() const;

  /**
   * @brief mouseClickToCardIndex converts the location of the specified mouse click to a card index in the CardPile.
   * @param event the MouseEvent
   * @return the index of the card that was clicked.
   */
  size_t mouseClickToCardIndex(QGraphicsSceneMouseEvent* event);

  /**
   * @brief draw handles drawing the specified CardPile to the specified painter.
   * @param painter the painter to use to draw.
   * @param cardPile the CardPile to be drawn.
   */
  static void draw(QPainter* painter, CardPile& cardPile);

  /**
   * @brief bounds calculates and returns the bounds for the specified CardPile.
   * @param cardPile the CardPile to calculate the bounding box for.
   * @return the bounding box for the specified CardPile.
   */
  static QRectF bounds(const CardPile& cardPile);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event);
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
  void dropEvent(QGraphicsSceneDragDropEvent* event);

private:
  TableauPile m_pile;
};

#endif // CARDPILEITEM_H
