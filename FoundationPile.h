#ifndef FOUNDATIONPILE_H
#define FOUNDATIONPILE_H

#include "CardPile.h"

#include <stack>

class FoundationPile : public CardPile
{
public:
  FoundationPile();

  bool accepts(const Card &) override;
};

#endif // FOUNDATIONPILE_H
