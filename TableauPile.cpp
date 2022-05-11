#include "TableauPile.h"

TableauPile::TableauPile()
{

}

bool TableauPile::accepts(const Card& card)
{
  if(isEmpty()) {
    return card.getRank() == Card::KING;
  }

  return top().isFlipped() && (top().isBlack() != card.isBlack()) &&
      (static_cast<int>(top().getRank()) - 1 == static_cast<int>(card.getRank()));
}
