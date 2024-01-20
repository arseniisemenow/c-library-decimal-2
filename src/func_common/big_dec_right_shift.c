#include "../s21_decimal.h"

void big_dec_right_shift(s21_decimal num_big[2], int shift) {
  if (shift < 0) shift = 0;
  for (int i = 0; i < 2 * SIZE_OF_MANTISSA - shift; i++) {
    int bit = big_dec_getbit(num_big, i + shift);
    big_dec_setbit(num_big, i, bit);
  }
  for (int i = 0; i < shift; i++) {
    big_dec_setbit(num_big, 2 * SIZE_OF_MANTISSA - 1 - i, 0);
  }
}