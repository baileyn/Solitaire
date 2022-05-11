#include "MainWindow.h"
#include "CardItem.h"
#include "DeckItem.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  m_scene = new QGraphicsScene;
  m_view = new QGraphicsView{m_scene};

  m_scene->setSceneRect(0, 0, 800, 600);
  m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setFixedSize(800, 600);
  setCentralWidget(m_view);

  initializeGame();
}

MainWindow::~MainWindow()
{
  delete m_scene;
}

void MainWindow::initializeGame()
{
  m_scene->addItem(new DeckItem{m_deck});
  m_deck.shuffle();

  for(size_t i = 0; i < Tableau::PILE_COUNT; i++) {
    TableauPile pile = m_tableau.getPile(i);
/*
    for(size_t j = 0; j < Tableau::PILE_COUNT; j++) {
      pile.add(m_deck.draw());
    }

    pile.top().flip();*/
  }
}
