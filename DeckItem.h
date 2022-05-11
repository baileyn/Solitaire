#ifndef DECKITEM_H
#define DECKITEM_H

#include "Deck.h"
#include "GameItem.h"
#include <QPainter>

class DeckItem : public GameItem
{
public:
  DeckItem(MainWindow* window, Deck& deck);

  QRectF boundingRect() const;
  void paint(QPainter *painter,
             const QStyleOptionGraphicsItem *option,
             QWidget *widget);

protected:
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

private:
  Deck& m_deck;
};

#endif // DECKITEM_H
