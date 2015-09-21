/*
 * card.h
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#ifndef POKAHANDTAS_CARD_H_
#define POKAHANDTAS_CARD_H_

// TODO(pignacio): check suit order
enum Suit { HEARTS, DIAMONDS, SPADES, CLUBS };

#define CARD_SUIT_SIZE 4

char Suit_letter(enum Suit suit);
enum Suit Suit_parse(char letter);

typedef struct _Card {
  enum Suit suit;
  int rank;
} Card;

#define CARD_MAX_RANK 13
#define CARD_MAX_INDEX (CARD_MAX_RANK * CARD_SUIT_SIZE - 1)

void Card_assert_valid(Card* card);
void Card_from_index(Card* card, int index);
int Card_index(Card* card);
void Card_text(Card* card, char* text);

void DEBUG_Card_print(Card* cards, int size);

#endif  // POKAHANDTAS_CARD_H_
