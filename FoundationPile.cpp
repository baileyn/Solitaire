#include "FoundationPile.h"

#include "Card.h"

#include <iostream>

FoundationPile::FoundationPile()
{

}

bool FoundationPile::accepts(const Card& card)
{
  if(cards().empty() && card.getRank() == Card::Rank::ACE) {
    return true;
  }

  return (static_cast<int>(cards().back().getRank()) + 1 ==
      static_cast<int>(card.getRank())) && cards().back().getSuit() == card.getSuit();
}
