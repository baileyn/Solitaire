#include "CardPile.h"

bool CardPile::isEmpty() const
{
  return m_cards.empty();
}

size_t CardPile::count() const
{
  return m_cards.size();
}

std::deque<Card>& CardPile::cards()
{
  return m_cards;
}

Card& CardPile::top()
{
  return m_cards.back();
}

bool CardPile::add(Card card, bool check)
{
  if(check && !accepts(card)) {
    return false;
  }

  m_cards.push_back(card);
  return true;
}
