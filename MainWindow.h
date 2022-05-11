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
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void removeCardItem(Card card);
  void resetDeck();
  bool playsOnFoundation(Card card);

private:
  void initializeGame();
  void addComponents();

private:
  QGraphicsView* m_view;
  QGraphicsScene* m_scene;

  Deck m_deck;
  Tableau m_tableau;

  std::array<FoundationPile, 4> m_foundations;
};

#endif // MAINWINDOW_H
