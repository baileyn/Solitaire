#include "MainWindow.h"
#include "CardItem.h"
#include "DeckItem.h"
#include "CardPileItem.h"
#include "FoundationPileItem.h"

#include <iostream>

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
  addComponents();
}

MainWindow::~MainWindow()
{
  delete m_scene;
}

void MainWindow::removeCardItem(Card card)
{
  for(auto item : m_scene->items()) {
    CardItem* cardItem = dynamic_cast<CardItem*>(item);

    if(cardItem) {
      if(cardItem->card().getRank() == card.getRank() &&
         cardItem->card().getSuit() == card.getSuit()) {
        m_scene->removeItem(cardItem);
        m_scene->update();
      }
    }
  }
}

void MainWindow::resetDeck()
{
  for(auto item : m_scene->items()) {
    CardItem* cardItem = dynamic_cast<CardItem*>(item);

    if(cardItem) {
      m_deck.add(cardItem->card());
      m_scene->removeItem(cardItem);
    }
  }
}

bool MainWindow::playsOnFoundation(Card card)
{
  for(auto& foundation : m_foundations) {
    if(foundation.add(card)) {
      return true;
    }
  }
  return false;
}

void MainWindow::initializeGame()
{
  m_deck.shuffle();

  for(size_t i = 0; i < Tableau::PILE_COUNT; i++) {
    TableauPile& pile = m_tableau.getPile(i);

    for(size_t j = 0; j <= i; j++) {
      pile.add(m_deck.draw(), false);
    }

    pile.top().flip();
  }
}

void MainWindow::addComponents()
{
  auto deck = new DeckItem{this, m_deck};

  for(size_t i = 0; i < Tableau::PILE_COUNT; i++) {
    auto pile = new CardPileItem{this, m_tableau.getPile(i)};
    pile->moveBy((CardItem::WIDTH + 20) * (i + 1), CardItem::HEIGHT + 20);
    m_scene->addItem(pile);
  }

  int offsetX = m_view->width() - (CardItem::WIDTH * 4) - (CardPileItem::PADDING * 3);

  for(size_t i = 0; i < 4; i++) {
    auto pile = new FoundationPileItem{this, m_foundations[i]};
    pile->moveBy(offsetX + (i * CardItem::WIDTH) + (i * CardPileItem::PADDING), 2);
    m_scene->addItem(pile);
  }

  m_scene->addItem(deck);
}
