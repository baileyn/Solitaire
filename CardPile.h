#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <vector>

class CardPile
{
public:
  Card& top();
  bool add(Card card, bool check=true);
  bool isEmpty();
  size_t count();
  std::vector<Card>& cards();

protected:
  virtual bool accepts(const Card&) {
    return false;
  }

private:
  std::vector<Card> m_cards;
};

#endif // CARDPILE_H
