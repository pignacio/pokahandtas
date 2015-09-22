/*
 * draw.c
 * Copyright (C) 2015 ignacio <rossi.ignacio@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include <assert.h>
#include <memory.h>
#include <stdlib.h>

#include "draw.h"

void Draw_init(Draw* draw, int size, Card* cards, int cards_size, bool repeat, bool sorted) {
  assert(cards_size > size);
  draw->size = size;
  draw->cards = cards;
  draw->cards_size = cards_size;
  draw->draw_indexes = malloc(sizeof(int) * size);
  draw->repeat = repeat;
  draw->sorted = sorted;
  if (repeat) {
    memset(draw->draw_indexes, 0, sizeof(int) * size);
  } else {
    for (int i = 0; i < size; ++i) {
      draw->draw_indexes[i] = sorted ? i : size - i - 1;
    }
  }
}

void Draw_free(Draw* draw) {
  free(draw->draw_indexes);
}

void Draw_current(Draw* draw, Card* cards) {
  for (int i = 0; i < draw->size; ++i) {
    cards[i] = draw->cards[draw->draw_indexes[i]];
  }
}

bool _ExDraw_advance(Draw* draw) {
  int index = 0;
  while (index != draw->size) {
    draw->draw_indexes[index]++;
    if (draw->draw_indexes[index] < draw->cards_size) {
      return false;
    }
    draw->draw_indexes[index] = 0;
    index++;
  }
  return true;
}

bool _Draw_advance(Draw* draw) {
  int index = 0;
  while (index != draw->size) {
    int limit =
        (draw->sorted && index < draw->size - 1) ? draw->draw_indexes[index + 1] : draw->cards_size;

    draw->draw_indexes[index]++;

    if (draw->draw_indexes[index] < limit) {
      return false;
    }
    int start = (draw->sorted && index > 0) ? draw->draw_indexes[index - 1] : 0;
    draw->draw_indexes[index] = start;
    index++;
  }
  return true;
}

bool _has_repeated(int* values, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (values[i] == values[j])
        return true;
    }
  }
  return false;
}

bool _are_sorted(int* values, int size) {
  for (int i = 1; i < size; ++i) {
    if (values[i - 1] > values[i])
      return false;
  }
  return true;
}

bool Draw_next(Draw* draw) {
  while (!_Draw_advance(draw)) {
    if (!draw->repeat && _has_repeated(draw->draw_indexes, draw->size))
      continue;
    return false;
  }
  return true;
}

