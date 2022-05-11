#include "Deck.h"

#include <random>
#include <algorithm>

Deck::Deck()
{
    for(int i = 0; i < Card::MAX_SUIT; i++) {
        for(int j = 0; j < Card::MAX_RANK; j++) {
            m_cards.push_back({static_cast<Card::Suit>(i), j});
        }
    }
}

Card Deck::draw()
{
    Card& card = m_cards.back();
    m_cards.pop_back();
    return card;
}

void Deck::shuffle()
{
    static std::random_device rng;
    static std::mt19937 urng(rng());
    std::shuffle(m_cards.begin(), m_cards.end(), urng);
}
