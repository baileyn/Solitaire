#ifndef TABLEAU_H
#define TABLEAU_H

#include "TableauPile.h"
#include <array>

class Tableau
{
public:
  /**
   * @brief PILE_COUNT the number of Tableau Piles that are in a game of Solitaire.
   */
  const static size_t PILE_COUNT = 7;

  /**
   * @brief Tableau constructs a new Tableau.
   */
  Tableau();
  ~Tableau();

  /**
   * @brief getPile gets the TableauPile that's located at the specified index.
   * @param idx the index of the TableauPile.
   * @return the TableauPile at the specified index.
   */
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
