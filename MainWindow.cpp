#include "MainWindow.h"
#include "Deck.h"
#include "Card.h"
#include "CardItem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene;
    view = new QGraphicsView{scene};

    scene->setSceneRect(0, 0, 800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    deck.shuffle();

    for(int i = 0; i < 5; i++) {
        scene->addItem(new CardItem{deck.draw()});
    }

    setFixedSize(800, 600);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete scene;
}
