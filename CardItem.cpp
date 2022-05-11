#include "CardItem.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QPen>
#include <QStaticText>
#include <string>

QString CardItem::RANKS[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
QBrush CardItem::BACK = QBrush{Qt::blue};
QPen CardItem::RED_PEN = QPen{Qt::red};
QPen CardItem::BLACK_PEN = QPen{Qt::black};

CardItem::CardItem(MainWindow* window, Card card)
  : GameItem{window}, m_card{card}
{
  setFlag(GraphicsItemFlag::ItemIsMovable);
}

QRectF CardItem::boundingRect() const
{
  return QRectF{0, 0, WIDTH, HEIGHT};
}

void CardItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
  QRectF rect = boundingRect();

  if(m_card.isFlipped()) {
    painter->fillRect(rect, QBrush{Qt::white});
    painter->setPen(m_card.isBlack() ? BLACK_PEN : RED_PEN);
    painter->drawRect(rect);

    QStaticText text{RANKS[m_card.getRank()]};
    auto textSize = text.size();
    painter->drawStaticText(0, 0, text);
    painter->drawStaticText(rect.width() - textSize.width(), rect.height() - textSize.height(), text);
  } else {
    painter->fillRect(rect, BACK);
  }
}

void CardItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseMoveEvent(event);

  auto cardRect = boundingRect();
  auto location = pos();

  if(location.x() < 0) {
    setPos(0, y());
  } else if(location.x() + cardRect.width() > scene()->width()) {
    setPos(scene()->width() - cardRect.width(), y());
  }

  if(y() < 0) {
    setPos(x(), 0);
  } else if(location.y() + cardRect.height() > scene()->height()) {
    setPos(x(), scene()->height() - cardRect.height());
  }
}

void CardItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
{
  m_card.flip();
  update();
}
