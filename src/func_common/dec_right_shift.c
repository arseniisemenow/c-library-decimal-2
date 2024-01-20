#include "../s21_decimal.h"

void dec_right_shift(s21_decimal *num, int shift) {
  if (shift < 0) shift = 0;
  for (int i = 0; i < SIZE_OF_MANTISSA - shift; i++) {
    int bit = dec_get_bit(*num, i + shift);
    dec_set_bit(num, i, bit);
  }
  for (int i = 0; i < shift; i++) {
    dec_set_bit(num, SIZE_OF_MANTISSA - 1 - i, 0);
  }
}