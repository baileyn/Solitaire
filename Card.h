#ifndef CARD_H
#define CARD_H

class Card
{
public:
    enum Suit {
        DIAMONDS, CLUBS, HEARTS, SPADES
    };

    Card(Suit suit, int rank);

    Suit getSuit() const;
    int getRank() const;

    bool isFlipped() const;
    void flip();

private:
    Suit m_suit;
    int m_rank;
    bool m_flipped;
};

#endif // CARD_H
