#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QGraphicsItem>

class MainWindow;

class GameItem : public QGraphicsItem
{
protected:
  GameItem(MainWindow* window);

  MainWindow* window() const;

private:
  MainWindow* m_window;
};

#endif // GAMEITEM_H
