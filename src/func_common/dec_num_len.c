#include "../s21_decimal.h"

int dec_num_len(s21_decimal num) {
  int res = 0;
  for (int i = 0; i < SIZE_OF_MANTISSA; i++) {
    if (dec_get_bit(num, i)) {
      res = i;
    }
  }
  return res + 1;
}