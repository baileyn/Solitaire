#include "DeckItem.h"

#include "CardItem.h"
#include <QBrush>
#include <QGraphicsScene>

DeckItem::DeckItem(Deck& deck)
    : m_deck{deck}
{

}

QRectF DeckItem::boundingRect() const
{
    return QRectF{0, 0, 75, 100};
}

void DeckItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    auto rect = boundingRect();

    if(m_deck.isEmpty()) {
        QPen pen{Qt::black};
        painter->drawRoundedRect(rect, 3, 3);
    } else {
        painter->fillRect(rect, QBrush(Qt::blue));
    }
}

void DeckItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
    if(m_deck.isEmpty()) {
        return;
    }

    auto card = m_deck.draw();
    card.flip();

    CardItem* item = new CardItem{card};
    scene()->addItem(item);
}
