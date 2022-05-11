#include "CardPile.h"

bool CardPile::isEmpty()
{
  return m_cards.empty();
}

Card& CardPile::top()
{
  return m_cards.top();
}

bool CardPile::add(Card& card)
{
  if(!accepts(card)) {
    return false;
  }

  m_cards.push(card);
  return true;
}
