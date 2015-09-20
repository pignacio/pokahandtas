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
  Draw draw;
  int draw_size = 2;
  Draw_init(&draw, draw_size, deck, FULL_DECK_SIZE, false, true);
  Card cards[draw_size];
  int count = 0;
  while (!Draw_next(&draw)) {
    Draw_current(&draw, cards);
    for (int i = 0; i < draw_size; i++) {
      DEBUG_Card_print(&cards[i], 1);
    }
    printf(" | ");
    count++;
  }
  printf("\n");
  printf("Total count: %d\n", count);
  Draw_free(&draw);
  puts("Bye world!");
  return 0;
}
