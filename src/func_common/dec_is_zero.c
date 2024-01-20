#include "../s21_decimal.h"

bool dec_is_zero(s21_decimal num) {
  bool res = 1;
  for (int i = 0; i < NUMBER_OF_BITS_IN_MANTISSA; i++) {
    res &= num.bits[i] == 0;
  }
  return res;
}