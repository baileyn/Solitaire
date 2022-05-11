#ifndef TABLEAUPILE_H
#define TABLEAUPILE_H

#include "CardPile.h"

class TableauPile : public CardPile
{
public:
  TableauPile();

  bool accepts(const Card& card);
};

#endif // TABLEAUPILE_H
