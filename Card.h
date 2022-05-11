#ifndef CARD_H
#define CARD_H

class Card
{
public:
  enum Suit {
    DIAMONDS, CLUBS, HEARTS, SPADES, MAX_SUIT
  };

  enum Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
    NINE, TEN, JACK, QUEEN, KING, MAX_RANK
  };

  Card(Suit suit, Rank rank);

  Suit getSuit() const;
  Rank getRank() const;

  bool isFlipped() const;
  void flip();
  bool isBlack() const;
  bool isRed() const;

private:
  Suit m_suit;
  Rank m_rank;
  bool m_flipped;
};

#endif // CARD_H
