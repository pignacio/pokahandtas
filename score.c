/*
 * score.c
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "score.h"

#include <memory.h>
#include <stdlib.h>

int Card_compare(const void *obj, const void *oobj) {
  const Card *card = obj;
  const Card *ocard = oobj;
  if (card->value == ocard->value) {
    return card->suit - ocard->suit;
  }
  return card->value - ocard->value;
}

Score Score_calculate(Card *cards) {
  Card hand[5];
  memcpy(hand, cards, sizeof(hand));
  qsort(hand, 5, sizeof(Card), Card_compare);

  printf("Sorted: ");
  DEBUG_Card_print(hand, 5);
  printf("\n");

  Score score;
  return score;
}
