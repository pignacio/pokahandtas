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
#include "draw.h"
#include "score.h"

void full_deck(Card *deck) {
  for (int i = 0; i <= CARD_MAX_INDEX; ++i) {
    Card_from_index(deck + i, i);
  }
}

#define FULL_DECK_SIZE 52  // 13 * 4

int main(int argc, char *argv[]) {
  puts("Hello world!");
  Card deck[FULL_DECK_SIZE];
  full_deck(deck);
  int draw_size = 5;
  Card cards[draw_size];
  cards[0] = deck[0];
  cards[1] = deck[1];
  Draw draw;
  Draw_init(&draw, draw_size, deck, FULL_DECK_SIZE, false, true);
  int count = 0;
  int hand_count[SCOREDHANDS_MAX];
  memset(hand_count, 0, sizeof(int) * SCOREDHANDS_MAX);
  do {
    if (count % 1000 == 0 && count > 0){
      printf("Processed: %d\n", count);
    }
    Draw_current(&draw, cards);
    Score score = Score_calculate(cards);
    hand_count[score.hand]++;
    count++;
  }
  while (!Draw_next(&draw)) ;
  printf("\n");
  printf("Total count: %d\n", count);
  for (int i = 0; i < SCOREDHANDS_MAX; ++i) {
    printf("Hands for %d: %d\n", i, hand_count[i]);
  }
  Draw_free(&draw);
  puts("Bye world!");
  return 0;
}
