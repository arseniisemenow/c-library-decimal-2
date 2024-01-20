#include "../s21_decimal.h"

void dec_mantissa_copy(s21_decimal *dest, s21_decimal src) {
  for (int i = 0; i < NUMBER_OF_BITS_IN_MANTISSA; i++) {
    dest->bits[i] = src.bits[i];
  }
}