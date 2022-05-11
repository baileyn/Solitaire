#ifndef FOUNDATIONPILEITEM_H
#define FOUNDATIONPILEITEM_H

#include "FoundationPile.h"
#include "GameItem.h"

class FoundationPileItem : public GameItem
{
public:
  /**
   * @brief FoundationPileItem creates a new FoundationPileItem to handle drawing a FoundationPile to the Window.
   * @param window the window to draw the FoundationPile on.
   * @param pile the FoundationPile to represent.
   */
  FoundationPileItem(MainWindow* window, FoundationPile& pile);

  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
  void dropEvent(QGraphicsSceneDragDropEvent* event);

private:
  FoundationPile& m_pile;
};

#endif // FOUNDATIONPILEITEM_H
