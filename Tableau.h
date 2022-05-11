#ifndef TABLEAU_H
#define TABLEAU_H

#include "TableauPile.h"
#include <array>

class Tableau
{
public:
  const static size_t PILE_COUNT = 7;

  Tableau();
  ~Tableau();

  TableauPile& getPile(size_t idx);

private:
  Tableau(Tableau& other) = delete;
  Tableau(Tableau&& other) = delete;
  Tableau& operator=(Tableau& other) = delete;
  Tableau&& operator=(Tableau&& other) = delete;

private:
  std::array<TableauPile, PILE_COUNT> m_piles;
};

#endif // TABLEAU_H
