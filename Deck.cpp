#include "Deck.h"

#include <random>
#include <algorithm>

Deck::Deck()
{
  for(int i = 0; i < Card::MAX_SUIT; i++) {
    for(int j = 0; j < Card::MAX_RANK; j++) {
      m_cards.push_back(Card{static_cast<Card::Suit>(i), static_cast<Card::Rank>(j)});
    }
  }
}

Card& Deck::draw()
{
  Card& card = m_cards.back();
  m_cards.pop_back();
  return card;
}

bool Deck::isEmpty() const
{
  return m_cards.size() == 0;
}

void Deck::shuffle()
{
  static std::random_device rng;
  static std::mt19937 urng(rng());
  std::shuffle(m_cards.begin(), m_cards.end(), urng);
}
