#include "Tableau.h"

Tableau::Tableau()
{
}

Tableau::~Tableau()
{
}

TableauPile& Tableau::getPile(size_t idx)
{
  return m_piles.at(idx);
}
