#include "../s21_decimal.h"

bool big_dec_is_zero(s21_decimal num_big[2]) {
  bool res = 1;
  for (int i = 0; i < NUMBER_OF_BITS_IN_MANTISSA; i++) {
    res &= (num_big[0]).bits[i] == 0;
  }
  for (int i = 0; i < NUMBER_OF_BITS_IN_MANTISSA; i++) {
    res &= (num_big[1]).bits[i] == 0;
  }
  return res;
}