#include "TableauItem.h"

#include "CardItem.h"

TableauItem::TableauItem(Tableau& tableau)
  : m_tableau{tableau}
{

}

QRectF TableauItem::boundingRect() const
{
  return QRectF{0, 0, Tableau::PILE_COUNT * CardItem::WIDTH + Tableau::PILE_COUNT * PADDING, CardItem::HEIGHT};
}

void TableauItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget* )
{
  painter->drawRect(boundingRect());
}
