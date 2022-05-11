#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <stack>

class CardPile
{
public:
  Card& top();
  bool add(Card& card);
  bool isEmpty();

protected:
  virtual bool accepts(const Card&) {
    return false;
  }

private:
  std::stack<Card> m_cards;
};

#endif // CARDPILE_H
