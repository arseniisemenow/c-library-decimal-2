#include "../s21_decimal.h"

void dec_set_zero(s21_decimal *num) {
  for (int i = 0; i < NUMBER_OF_BITS_IN_MANTISSA; i++) {
    num->bits[i] = 0;
  }
}
