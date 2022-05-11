#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <deque>

class Deck
{
public:
  /**
   * @brief Deck creates a new Deck.
   */
  Deck();

  /**
   * @brief draw draws a card from the Deck.
   * @return the Card that was drawn from the Deck.
   */
  Card draw();

  /**
   * @brief shuffle shuffles the Deck.
   */
  void shuffle();

  /**
   * @brief add adds the specified Card back in the deck.
   * @param card the Card to add.
   */
  void add(Card card);

  /**
   * @brief isEmpty determines whether or not the Deck is empty.
   * @return true if the Deck is empty.
   * @return false if the Deck isn't empty.
   */
  bool isEmpty() const;

private:
  Deck(Deck& deck) = delete;
  Deck& operator=(Deck& other) = delete;

private:
  std::deque<Card> m_cards;
};

#endif // DECK_H
