#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <deque>

class CardPile
{
public:
  /**
   * @brief ~CardPile a virtual deconstructor to allow base classes deconstructors to be called.
   */
  virtual ~CardPile() {}

  /**
   * @brief getTop gets the top card on the pile.
   * @return a reference to the top card on the pile.
   */
  Card& getTop();

  /**
   * @brief add attempts to add the specified card onto the CardPile. If check is true,
   *        then this function will call CardPile::accepts(const Card&) to determine whether
   *        the pile can accept the specified card.
   * @param card the card to attempt to place.
   * @param check whether or not to check if the card can be placed.
   * @return true if the card was successfully placed on the pile.
   * @return false if the card wasn't placed on the pile.
   */
  bool add(Card card, bool check=true);

  /**
   * @brief isEmpty determins if this CardPile is empty or not.
   * @return true if the CardPile is empty.
   * @return false if the CardPile isn't empty.
   */
  bool isEmpty() const;

  size_t getCount() const;

  std::deque<Card>& cards();

protected:
  virtual bool accepts(const Card&) = 0;

private:
  std::deque<Card> m_cards;
};

#endif // CARDPILE_H
