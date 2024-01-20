#include "../s21_decimal.h"

int mantissa_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return is_mantissa_equal(num1, num2) || mantissa_is_greater(num1, num2);
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return s21_is_equal(num1, num2) || s21_is_greater(num1, num2);
}

/* big decimal */

int big_dec_mantissa_is_greater_or_equal(s21_decimal num1[2],
                                         s21_decimal num2[2]) {
  return big_dec_mantissa_is_equal(num1, num2) ||
         big_dec_mantissa_is_greater(num1, num2);
}
