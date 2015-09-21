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

enum ScoredHands {
  HIGH_CARD,
  PAIR,
  DOUBLE_PAIR,
  THREE,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  POKER,
  STRAIGHT_FLUSH
};

typedef struct _Score {
  enum ScoredHands hand;
  int subscore;
} Score;

int Score_compare(const void *obj, const void *oobj);
Score Score_calculate(Card *cards);

#endif  // POKAHANDTAS_SCORE_H_
