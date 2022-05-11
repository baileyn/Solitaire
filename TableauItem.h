#ifndef TABLEAUITEM_H
#define TABLEAUITEM_H

#include "Tableau.h"
#include <QGraphicsItem>
#include <QPainter>

class TableauItem : public QGraphicsItem
{
public:
  static const int PADDING = 20;

  TableauItem(Tableau& tableau);

  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
  Tableau& m_tableau;
};

#endif // TABLEAUITEM_H
