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
  SelectionPile(MainWindow* window, TableauPile& original);

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
