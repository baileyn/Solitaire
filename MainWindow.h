#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Deck.h"
#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsView* view;
    QGraphicsScene* scene;

    Deck deck;
};

#endif // MAINWINDOW_H
