#include "CardItem.h"

#include "MainWindow.h"

#include <QtWidgets>
#include <QList>

QString CardItem::RANKS[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
QString CardItem::SUITS[] = { "♢", "♣", "♡", "♠" };
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
  draw(painter, m_card, 0, 0);
}

Card CardItem::getCard()
{
  return m_card;
}

void CardItem::draw(QPainter* painter, Card& card, qreal x, qreal y)
{
  QRectF rect = QRectF{x, y, CardItem::WIDTH, CardItem::HEIGHT};

  if(card.isFlipped()) {
    painter->fillRect(rect, QBrush{Qt::white});
    painter->setPen(card.isBlack() ? CardItem::BLACK_PEN : CardItem::RED_PEN);
    painter->drawRect(rect);

    QStaticText topLeft{CardItem::RANKS[card.getRank()] + SUITS[card.getSuit()]};
    QStaticText bottomRight{SUITS[card.getSuit()] + CardItem::RANKS[card.getRank()]};
    auto textSize = bottomRight.size();
    painter->drawStaticText(x, y, topLeft);
    painter->drawStaticText(x + (rect.width() - textSize.width()), y + (rect.height() - textSize.height()), bottomRight);
  } else {
    painter->fillRect(rect, CardItem::BACK);
  }
}

void CardItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  QDrag *drag = new QDrag(event->widget());
  QMimeData *mime = new QMimeData;

  QList<Card> list{};
  list.append(getCard());
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

void CardItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
  if(window()->playsOnFoundation(m_card)) {
    window()->removeCardItem(m_card);
  }
}
