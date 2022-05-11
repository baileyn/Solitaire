#include "FoundationPile.h"

#include "Card.h"

#include <iostream>

FoundationPile::FoundationPile()
{

}

bool FoundationPile::accepts(const Card& card)
{
  if(isEmpty()) {
    return card.getRank() == Card::ACE;
  }

  return (static_cast<int>(top().getRank()) + 1 ==
      static_cast<int>(card.getRank())) && top().getSuit() == card.getSuit();
}
