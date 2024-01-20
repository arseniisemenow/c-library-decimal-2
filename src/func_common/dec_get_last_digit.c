#include "../s21_decimal.h"

int dec_get_last_digit(s21_decimal num) {
  s21_decimal divisor = LITERAL_DECIMAL_TEN;
  s21_decimal remainder = {0};
  base_div(num, divisor, &num, &remainder);
  return (int)remainder.bits[0];
}