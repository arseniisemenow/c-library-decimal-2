#include "../s21_decimal.h"

void s21_from_decimal_to_big_decimal(s21_decimal num, s21_decimal num_big[2]) {
  int sign = dec_get_sign(num);
  big_dec_init(num_big);
  num_big[0] = num;
  big_dec_setsign(num_big, sign);
}