/*
 * score.c
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "score.h"

#include <memory.h>
#include <stdlib.h>

void CardCount_count(CardCount *count, Card *cards, int size) {
  memset(count->ranks, 0, sizeof(int) * (CARD_MAX_RANK + 1));
  memset(count->suits, 0, sizeof(int) * CARD_SUIT_SIZE);
  for (int i = 0; i < size; ++i) {
    Card_assert_valid(&cards[i]);
    count->ranks[cards[i].rank]++;
    count->suits[cards[i].suit]++;
  }
}

bool CardCount_has_n_ranks_with_k(CardCount *count, int n, int k) {
  int c = 0;
  for (int i = 1; i <= CARD_MAX_RANK; ++i) {
    if (count->ranks[i] == k)
      c++;
  }
  return c >= n;
}

bool CardCount_has_n_suits_with_k(CardCount *count, int n, int k) {
  int c = 0;
  for (int i = 0; i <= CARD_SUIT_SIZE; ++i) {
    if (count->suits[i] == k)
      c++;
  }
  return c >= n;
}

int Card_compare(const void *obj, const void *oobj) {
  const Card *card = obj;
  const Card *ocard = oobj;
  if (card->rank == ocard->rank) {
    return card->suit - ocard->suit;
  }
  return card->rank - ocard->rank;
}

Score Score_calculate(Card *cards) {
  int size = 5;
  Card hand[size];
  memcpy(hand, cards, sizeof(hand));
  qsort(hand, size, sizeof(Card), Card_compare);
  CardCount count;
  CardCount_count(&count, hand, size);

  bool is_flush = CardCount_has_n_suits_with_k(&count, 1, 5);
  bool is_straight = true;
  for (int i = 0; i < 4; ++i) {
    if (hand[i].rank + 1 != hand[i + 1].rank)
      is_straight = false;
  }

  Score score;

  if (is_straight && is_flush)
    score.hand = STRAIGHT_FLUSH;
  else if (CardCount_has_n_ranks_with_k(&count, 1, 4))
    score.hand = POKER;
  else if (CardCount_has_n_ranks_with_k(&count, 1, 3) && CardCount_has_n_ranks_with_k(&count, 1, 2))
    score.hand = FULL_HOUSE;
  else if (is_flush)
    score.hand = FLUSH;
  else if (is_straight)
    score.hand = STRAIGHT;
  else if (CardCount_has_n_ranks_with_k(&count, 1, 3))
    score.hand = THREE;
  else if (CardCount_has_n_ranks_with_k(&count, 2, 2))
    score.hand = TWO_PAIR;
  else if (CardCount_has_n_ranks_with_k(&count, 1, 2))
    score.hand = PAIR;
  else
    score.hand = HIGH_CARD;
  return score;
}
