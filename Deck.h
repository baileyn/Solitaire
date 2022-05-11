#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <deque>

class Deck
{
public:
  Deck();

  Card draw();
  void shuffle();
  void add(Card card);
  bool isEmpty() const;

private:
  Deck(Deck& deck) = delete;
  Deck& operator=(Deck& other) = delete;

private:
  std::deque<Card> m_cards;
};

#endif // DECK_H
