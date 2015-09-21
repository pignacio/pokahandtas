/*
 * score.h
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#ifndef POKAHANDTAS_SCORE_H_
#define POKAHANDTAS_SCORE_H_

#include <stdbool.h>

#include "card.h"

typedef enum _ScoredHands {
  HIGH_CARD,
  PAIR,
  TWO_PAIR,
  THREE,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  POKER,
  STRAIGHT_FLUSH
} ScoredHands;

#define SCOREDHANDS_MAX (STRAIGHT_FLUSH + 1)

typedef struct _Score {
  ScoredHands hand;
  int subscore;
} Score;

int Score_compare(const void *obj, const void *oobj);
Score Score_calculate(Card *cards);

typedef struct _CardCount {
  int suits[CARD_SUIT_SIZE];
  int ranks[CARD_MAX_RANK + 1];
} CardCount;

void CardCount_count(CardCount *count, Card *cards, int size);
bool CardCount_has_n_ranks_with_k(CardCount *count, int n, int k);
bool CardCount_has_n_suits_with_k(CardCount *count, int n, int k);

#endif  // POKAHANDTAS_SCORE_H_
