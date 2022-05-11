#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Deck.h"
#include "FoundationPile.h"
#include "Tableau.h"

#include <QMainWindow>
#include <QGraphicsView>

#include <array>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  /**
   * @brief MainWindow creates a new Window
   * @param parent the parent for this Window.
   */
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  /**
   * @brief removeCardItem removes all CardItems that represent the specified Card from this Window.
   * @param card the Card to remove.
   */
  void removeCardItem(Card card);

  /**
   * @brief resetDeck puts all of the cards that have been flipped over back into the Deck.
   */
  void resetDeck();

  /**
   * @brief playsOnFoundation is a helper function to determine if the specified Card is able
   *        to be played on any of the foundations.
   * @param card the Card to inspect.
   * @return true if it's able to be played.
   * @return false if it's not able to be played.
   */
  bool playsOnFoundation(Card card);

private:
  /**
   * @brief initializeGame initializes a new game of solitaire.
   */
  void initializeGame();

  /**
   * @brief addComponents adds all of the appropriate components to the Window.
   */
  void addComponents();

private:
  QGraphicsView* m_view;
  QGraphicsScene* m_scene;

  Deck m_deck;
  Tableau m_tableau;

  std::array<FoundationPile, 4> m_foundations;
};

#endif // MAINWINDOW_H
