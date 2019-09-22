// Copyright 2019 Plotnikov Aleksey <alex280201@gmail.com>

#include <header.hpp>

void direct_movement(size_t size_mbits) {
  size_t size = 128 * 1024 * size_mbits;
  size /= 4;
  int* buf = new int[size]();
  int i = 0;
  for (; static_cast<size_t>(i) < size / 64; i++) {
    buf[i * 64] = (i + 1) * 64;
  }
  i--;
  i *= 64;
  buf[i] = 0;
  i = 0;
  size_t k = 0;
  size_t begin = clock();
  while (k < 1000) {
    x3(x10000(i = buf[i];)) k++;
  }
  size_t end = clock();
  delete[] buf;
  size_t res = end - begin;
  std::cout << res / 30. << " ns\n";
}

void reverse_movement(size_t size_mbits) {
  size_t size = 128 * 1024 * size_mbits;
  size /= 4;
  int* buf = new int[size]();
  int i = 1;
  for (; static_cast<size_t>(i) < size / 64; i++) {
    buf[i * 64] = (i - 1) * 64;
  }
  i--;
  i *= 64;
  buf[0] = i;
  i = 0;
  size_t k = 0;
  size_t begin = clock();
  while (k < 1000) {
    x3(x10000(i = buf[i];)) k++;
  }
  size_t end = clock();
  delete[] buf;
  size_t res = end - begin;
  std::cout << res / 30. << " ns\n";
}

int* random_filling(size_t size) {
  int* res = new int[size]();
  size_t k = size / 64;
  int* temp = new int[k]();
  for (size_t ind = 0; ind < k; ind++) {
    temp[ind] = ind * 64;
  }
  res[64] = 0;
  size_t i;
  srand(time(NULL));
  for (size_t ind = 0; ind < k; ind++) {
    bool is_used = true;
    while (is_used) {
      unsigned int cl = clock();
      i = rand_r(&cl) % k;
      if (i != 1 && res[i * 64] == 0) {
        is_used = false;
        res[i * 64] = temp[ind];
      }
    }
  }
  delete[] temp;
  return res;
}

void random_movement(size_t size_mbits) {
  size_t size = 128 * 1024 * size_mbits;
  size /= 4;
  auto buf = random_filling(size);
  int i = 0;
  size_t k = 0;
  size_t begin = clock();
  while (k < 1000) {
    x3(x10000(i = buf[i];)) k++;
  }
  size_t end = clock();
  delete[] buf;
  size_t res = end - begin;
  std::cout << res / 30. << " ns\n";
}

void report(mode _mode) {
  std::cout << "investigation:\n  travel_order: ";
  if (_mode == DIR) {
    std::cout << "\"direct\"\n  experiments:";
    size_t number = 1;
    for (size_t i = 2; i <= 128; i *= 2) {
      if (i == 128) i = 96;
      std::cout << "\n  - experiment:\n      number: " << number;
      std::cout << "\n      input_data:\n        buffer_size: \"" << i / 8.
                << "mb\"";
      std::cout << "\n      results:\n        duration: \"";
      direct_movement(i);
      number++;
    }
  }
  if (_mode == REV) {
    std::cout << "\"reverse\"\n  experiments:";
    size_t number = 1;
    for (size_t i = 2; i <= 128; i *= 2) {
      if (i == 128) i = 96;
      std::cout << "\n  - experiment:\n      number: " << number;
      std::cout << "\n      input_data:\n        buffer_size: \"" << i / 8.
                << "mb\"";
      std::cout << "\n      results:\n        duration: \"";
      reverse_movement(i);
      number++;
    }
  }
  if (_mode == RAND) {
    std::cout << "\"random\"\n  experiments:";
    size_t number = 1;
    for (size_t i = 2; i <= 128; i *= 2) {
      if (i == 128) i = 96;

      std::cout << "\ni=" << i << "\n";

      std::cout << "\n  - experiment:\n      number: " << number;
      std::cout << "\n      input_data:\n        buffer_size: \"" << i / 8.
                << "mb\"";
      std::cout << "\n      results:\n        duration: \"";
      random_movement(i);
      number++;
    }
  }
}
