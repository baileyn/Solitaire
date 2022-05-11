#include "CardItem.h"

#include <QtWidgets>
#include <QList>

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

Card CardItem::card()
{
  return m_card;
}

void CardItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  QDrag *drag = new QDrag(event->widget());
  QMimeData *mime = new QMimeData;

  QList<Card> list{};
  list.append(card());
  mime->setProperty("cards", qVariantFromValue(list));
  drag->setMimeData(mime);

  QPixmap pixmap(CardItem::WIDTH, CardItem::HEIGHT);
  pixmap.fill(Qt::white);

  QPainter painter(&pixmap);
  painter.setRenderHint(QPainter::Antialiasing);
  paint(&painter, 0, 0);
  painter.end();

  drag->setPixmap(pixmap);
  drag->setHotSpot(QPoint(CardItem::WIDTH / 2, CardItem::HEIGHT / 2));

  Qt::DropAction action = drag->exec();

  if(action == Qt::MoveAction) {
    scene()->removeItem(this);
  }
}
