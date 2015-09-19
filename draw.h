/*
 * draw.h
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#ifndef POKAHANDTAS_DRAW_H_
#define POKAHANDTAS_DRAW_H_

#include <stdbool.h>

#include "card.h"

struct _Draw {
  int size;
  Card *cards;
  int cards_size;
  int *draw_indexes;
  bool repeat;
  bool sorted;
};
typedef struct _Draw Draw;

void Draw_init(Draw *draw, int size, Card *cards, int cards_size, bool repeat, bool sorted);
void Draw_free(Draw *draw);
void Draw_current(Draw *draw, Card *cards);
bool Draw_next(Draw *draw);

#endif  // POKAHANDTAS_DRAW_H_
