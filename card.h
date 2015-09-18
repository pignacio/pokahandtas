/*
 * card.h
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#ifndef POKAHANDTAS_CARD_H_
#define POKAHANDTAS_CARD_H_

enum Suit { HEARTS, DIAMONDS, SPADES, CLUBS };

#define CARD_SUIT_SIZE 4

char Suit_letter(enum Suit suit);
enum Suit Suit_parse(char letter);

struct _Card {
  enum Suit suit;
  int value;
};
typedef struct _Card Card;

#define CARD_MAX_VALUE 13
#define CARD_MAX_INDEX (CARD_MAX_VALUE * CARD_SUIT_SIZE - 1)

void Card_assert_valid(Card* card);
void Card_from_index(Card* card, int index);
int Card_index(Card* card);
void Card_text(Card* card, char* text);

#endif  // POKAHANDTAS_CARD_H_
