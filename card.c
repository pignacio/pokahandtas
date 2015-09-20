/*
 * card.c
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "card.h"

#include <assert.h>
#include <stdio.h>

char Suit_letter(enum Suit suit) {
  switch (suit) {
    case HEARTS:
      return 'h';
    case DIAMONDS:
      return 'd';
    case SPADES:
      return 's';
    case CLUBS:
      return 'c';
  }
}

void Card_assert_valid(Card* card) {
  assert(1 <= card->value && card->value <= CARD_MAX_VALUE);
}

int Card_index(Card* card) {
  Card_assert_valid(card);
  return card->suit * 13 + card->value - 1;
}

void Card_from_index(Card* card, int index) {
  assert(0 <= index && index <= CARD_MAX_INDEX);
  card->value = index % 13 + 1;
  card->suit = index / 13;
}

char _Card_value_letter(int value) {
  assert(0 < value && value <= CARD_MAX_VALUE);
  switch (value) {
    case 1:
      return 'A';
    case 10:
      return 'T';
    case 11:
      return 'J';
    case 12:
      return 'Q';
    case 13:
      return 'K';
    default:
      return '0' + value;
  }
}

void Card_text(Card* card, char* text) {
  sprintf(text, "%c%c", _Card_value_letter(card->value), Suit_letter(card->suit));
}

void DEBUG_Card_print(Card* cards, int size) {
  char text[3];
  for (int i = 0; i < size; ++i) {
    Card_text(cards + i, text);
    printf("%s", text);
  }
}
