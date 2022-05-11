#include "CardPile.h"

bool CardPile::isEmpty() const
{
  return m_cards.empty();
}

size_t CardPile::getCount() const
{
  return m_cards.size();
}

std::deque<Card>& CardPile::getCards()
{
  return m_cards;
}

Card& CardPile::getTop()
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
