/*
 * pokahandtas.c
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include <assert.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "card.h"

void print_card(Card *card) {
  Card_assert_valid(card);
  char text[2];
  Card_text(card, text);
  printf("%s", text);
}

struct _Hand {
  int size;
  int *card_indexes;
  bool done;
};
typedef struct _Hand Hand;

void Hand_init(Hand *hand, int size) {
  hand->size = size;
  hand->card_indexes = malloc(sizeof(int) * size);
  hand->done = false;
  memset(hand->card_indexes, 0, sizeof(int) * size);
}

void Hand_free(Hand *hand) {
  free(hand->card_indexes);
}

void Hand_current(Hand *hand, Card *cards) {
  for (int i = 0; i < hand->size; i++) {
    Card_from_index(&cards[i], hand->card_indexes[i]);
  }
}

bool _Hand_advance(Hand *hand) {
  int index = 0;
  while (index != hand->size) {
    hand->card_indexes[index]++;
    if (hand->card_indexes[index] <= CARD_MAX_INDEX) {
      return false;
    }
    hand->card_indexes[index] = 0;
    index++;
  }
  return true;
}

bool _has_repeated(int *values, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (values[i] == values[j])
        return true;
    }
  }
  return false;
}

bool Hand_next(Hand *hand) {
  while (!_Hand_advance(hand)) {
    if (!_has_repeated(hand->card_indexes, hand->size))
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  puts("Hello world!");
  Hand hand;
  int hand_size = 3;
  Hand_init(&hand, hand_size);
  Card cards[hand_size];
  int count = 0;
  while (!Hand_next(&hand)) {
    Hand_current(&hand, cards);
    for (int i = 0; i < hand_size; i++) {
      print_card(&cards[i]);
    }
    printf(" | ");
    count++;
  }
  printf("\n");
  printf("Total count: %d\n", count);
  Hand_free(&hand);
  puts("Bye world!");
  return 0;
}
