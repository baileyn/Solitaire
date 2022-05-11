#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QGraphicsItem>

class MainWindow;

class GameItem : public QGraphicsItem
{
protected:
  /**
   * @brief GameItem constructs a new GameItem that classes should subclass to be added to the game.
   * @param window the window that this GameItem is for.
   */
  GameItem(MainWindow* window);

  /**
   * @brief window returns the pointer to the Window that this GameItem is for.
   * @return the pointer to the Window that this GameItem is for.
   */
  MainWindow* window() const;

private:
  MainWindow* m_window;
};

#endif // GAMEITEM_H
