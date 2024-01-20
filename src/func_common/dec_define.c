#include "../s21_decimal.h"

s21_decimal dec_define(unsigned bits1, unsigned bits2, unsigned bits3,
                       int scale, int sign) {
  s21_decimal num = {{bits1, bits2, bits3, 0}};
  dec_set_scale(&num, scale);
  dec_set_sign(&num, sign);
  return num;
}