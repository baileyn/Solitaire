#ifndef FOUNDATIONPILE_H
#define FOUNDATIONPILE_H

#include "CardPile.h"

#include <stack>

class FoundationPile : public CardPile
{
public:
  /**
   * @brief FoundationPile creates a new FoundationPile.
   */
  FoundationPile();

  /**
   * @brief accepts determines whether or not the specified Card is accepted by this FoundationPile.
   * @return true if the Card is accepted.
   * @return false if the Card isn't accepted.
   */
  bool accepts(const Card &) override;
};

#endif // FOUNDATIONPILE_H
