#ifndef CARDITEM_H
#define CARDITEM_H

#include "Card.h"

#include <QWidget>
#include <QGraphicsItem>

class CardItem : public QGraphicsItem
{
public:
    CardItem(Card card);

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

private:
    Card m_card;
};

#endif // CARDITEM_H
