#include "../s21_decimal.h"

s21_decimal dec_twos_complement(s21_decimal num) {
  if (!dec_get_sign(num)) return num;

  s21_decimal res = {0};
  s21_decimal one = {{1, 0, 0, 0}};

  for (int i = 0; i < NUMBER_OF_BITS_IN_MANTISSA; i++) {
    res.bits[i] = ~num.bits[i];
  }
  res.bits[header_bit] = num.bits[header_bit];
  add_mantissa(one, res, &res);
  return res;
}