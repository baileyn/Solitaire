#ifndef SELECTIONPILE_H
#define SELECTIONPILE_H

#include "CardPile.h"
#include "GameItem.h"

#include <QtWidgets>

class MainWindow;
class TableauPile;

class SelectionPile : public CardPile, public GameItem
{
public:
  /**
   * @brief SelectionPile is a GameItem that is used to represent a selection of cards
   *        that have been chosen by the user.
   * @param window the window to draw this GameItem on.
   * @param original the original TableauPile that the cards were taken from.
   */
  SelectionPile(MainWindow* window, TableauPile& original);

  /**
   * @brief accepts doesn't do anything for a SelectionPile.
   * @param card
   * @return
   */
  bool accepts(const Card& card);

  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

  void fireMouseMoveEvent(QGraphicsSceneMouseEvent* event) { mouseMoveEvent(event); }

protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

private:
  TableauPile& m_original;
};

#endif // SELECTIONPILE_H
