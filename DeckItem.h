#ifndef DECKITEM_H
#define DECKITEM_H

#include "Deck.h"
#include "GameItem.h"
#include <QPainter>

class DeckItem : public GameItem
{
public:
  /**
   * @brief DeckItem create a new DeckItem that represents the specified Deck.
   * @param window the window to draw the DeckItem on.
   * @param deck the Deck to be represented by this DeckItem.
   */
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
