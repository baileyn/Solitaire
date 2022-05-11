#include "CardItem.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QPainter>
#include <QPen>
#include <QStaticText>
#include <string>

#include <iostream>

CardItem::CardItem(Card card)
    : m_card{card}
{
    setFlag(GraphicsItemFlag::ItemIsMovable);
}

QRectF CardItem::boundingRect() const
{
    return QRectF{0, 0, 75, 100};
}

void CardItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    static QString RANKS[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    QRectF rect = boundingRect();

    if(m_card.isFlipped()) {
        auto red = static_cast<int>(m_card.getSuit()) % 2 == 0;

        QPen pen(red ? Qt::red : Qt::black, 1);
        painter->setPen(pen);
        painter->drawRect(rect);

        QStaticText text{RANKS[m_card.getRank()]};
        auto textSize = text.size();
        painter->drawStaticText(0, 0, text);
        painter->drawStaticText(rect.width() - textSize.width(), rect.height() - textSize.height(), text);
    } else {
        painter->fillRect(rect, QBrush{Qt::blue});
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

void CardItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    m_card.flip();
    update();
}
