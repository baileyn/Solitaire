#include "GameItem.h"

GameItem::GameItem(MainWindow* window)
  : m_window{window}
{

}

MainWindow* GameItem::window() const
{
  return m_window;
}
