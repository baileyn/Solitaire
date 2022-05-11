#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <deque>

class CardPile
{
public:
  Card& top();
  bool add(Card card, bool check=true);
  bool isEmpty() const;
  size_t count() const;

  std::deque<Card>& cards();

protected:
  virtual bool accepts(const Card&) {
    return false;
  }

private:
  std::deque<Card> m_cards;
};

#endif // CARDPILE_H
