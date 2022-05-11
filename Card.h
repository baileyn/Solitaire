#ifndef CARD_H
#define CARD_H

#include <QMetaType>

class Card
{
public:
  /**
   * @brief The Suit enum holds the different types of suits a playing card can be
   */
  enum Suit {
    DIAMONDS, CLUBS, HEARTS, SPADES, MAX_SUIT
  };

  /**
   * @brief The Rank enum holds the different types of ranks a playing card can be
   */
  enum Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
    NINE, TEN, JACK, QUEEN, KING, MAX_RANK
  };

  /**
   * @brief Card constructor should never be used by the programmer. This only exists to allow for
   * Qt to use it correctly.
   */
  Card() {}

  /**
   * @brief Card constructs a new Card type with the specified Suit and Rank.
   * @param suit the suit of the card
   * @param rank the rank of the card
   *
   * @see Rank
   * @see Suit
   */
  Card(Suit suit, Rank rank);

  /**
   * @brief getSuit returns the suit of the playing card
   * @return the suit of the playing card
   */
  Suit getSuit() const;

  /**
   * @brief getRank returns the rank of the playing card
   * @return the rank of the playing card
   */
  Rank getRank() const;

  /**
   * @brief isFlipped determines whether or not the card is flipped over (face up).
   * @return true if the card is face up
   * @return false if the card is face down
   */
  bool isFlipped() const;

  /**
   * @brief flip flips the card over. If the card was face down, it's now face up, and vice versa.
   */
  void flip();

  /**
   * @brief isBlack determins whether the card is generally portrayed as being black.
   * @return true if the card is generally portrayed as being black (Clubs or Spades).
   * @return false if the card is generally portayed as being red (Diamonds or Hearts).
   */
  bool isBlack() const;


  /**
   * @brief isBlack determins whether the card is generally portrayed as being red.
   * @return true if the card is generally portayed as being red (Diamonds or Hearts).
   * @return false if the card is generally portrayed as being black (Clubs or Spades).
   */
  bool isRed() const;

private:
  Suit m_suit;
  Rank m_rank;
  bool m_flipped;
};

Q_DECLARE_METATYPE(Card)

#endif // CARD_H
