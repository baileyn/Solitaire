#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Deck.h"
#include "Tableau.h"
#include <QMainWindow>
#include <QGraphicsView>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  void initializeGame();
  void addComponents();

private:
  QGraphicsView* m_view;
  QGraphicsScene* m_scene;

  Deck m_deck;
  Tableau m_tableau;
};

#endif // MAINWINDOW_H
