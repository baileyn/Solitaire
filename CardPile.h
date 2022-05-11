#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <stack>

class CardPile
{
public:
    CardPile();

    bool add(Card& card);
    Card& top();

protected:
    virtual bool accepts(const Card& card) const;

private:
    std::stack<Card> m_cards;
};

#endif // CARDPILE_H
