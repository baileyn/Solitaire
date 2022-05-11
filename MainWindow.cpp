#include "MainWindow.h"
#include "CardItem.h"
#include "DeckItem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene;
    view = new QGraphicsView{scene};

    scene->setSceneRect(0, 0, 800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    deck.shuffle();

    scene->addItem(new DeckItem{deck});

    setFixedSize(800, 600);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete scene;
}
