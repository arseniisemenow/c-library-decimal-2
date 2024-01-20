#include "../s21_decimal.h"

void big_dec_left_shift(s21_decimal num[2], int shift) {
  if (shift < 0) shift = 0;
  for (int i = 2 * SIZE_OF_MANTISSA - 1; i >= shift; i--) {
    int bit = big_dec_getbit(num, i - shift);
    big_dec_setbit(num, i, bit);
  }
  for (int i = 0; i < shift; i++) {
    big_dec_setbit(num, i, 0);
  }
}