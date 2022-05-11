#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <deque>

class CardPile
{
public:
  virtual ~CardPile() {}

  Card& top();
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
