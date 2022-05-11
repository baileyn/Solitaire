#ifndef FOUNDATIONPILEITEM_H
#define FOUNDATIONPILEITEM_H

#include "FoundationPile.h"
#include "GameItem.h"

class FoundationPileItem : public GameItem
{
public:
  FoundationPileItem(MainWindow* window, FoundationPile& m_pile);

  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
  void dropEvent(QGraphicsSceneDragDropEvent* event);

private:
  FoundationPile& m_pile;
};

#endif // FOUNDATIONPILEITEM_H
