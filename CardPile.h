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

  Card& getTop();
  bool add(Card card, bool check=true);
  bool isEmpty() const;
  size_t count() const;

  std::deque<Card>& cards();

protected:
  virtual bool accepts(const Card&) = 0;

private:
  std::deque<Card> m_cards;
};

#endif // CARDPILE_H
