// Copyright 2019 Plotnikov Aleksey <alex280201@gmail.com>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <ctime>

#define x3(x) x x x
#define x10(x) x x x x x x x x x x
#define x100(x) \
  x10(x) x10(x) x10(x) x10(x) x10(x) x10(x) x10(x) x10(x) x10(x) x10(x)
#define x1000(x)                                                          \
  x100(x) x100(x) x100(x) x100(x) x100(x) x100(x) x100(x) x100(x) x100(x) \
      x100(x)
#define x10000(x)                                                         \
  x1000(x) x1000(x) x1000(x) x1000(x) x1000(x) x1000(x) x1000(x) x1000(x) \
      x1000(x) x1000(x)

// cache_size['1'] = 0.25 mb;
// cache_size['2'] = 1 mb;
// cache_size['3'] = 8 mb;

// 0.25mb < 0.5mb < 1mb < 2mb < 4mb < 8mb < 12mb

enum mode { DIR, REV, RAND };

void direct_movement(size_t size_mbits);

void reverse_movement(size_t size_mbits);

int* random_filling(size_t size);

void random_movement(size_t size_mbits);

void report(mode _mode);

#endif // INCLUDE_HEADER_HPP_
