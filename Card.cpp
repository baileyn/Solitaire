#include "Card.h"

Card::Card(Suit suit, int rank)
    : m_suit{suit}, m_rank{rank}, m_flipped{false}
{

}

Card::Suit Card::getSuit() const
{
    return m_suit;
}

int Card::getRank() const
{
    return m_rank;
}

bool Card::isFlipped() const
{
    return m_flipped;
}

void Card::flip()
{
    m_flipped = !m_flipped;
}
