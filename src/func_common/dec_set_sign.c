#include "../s21_decimal.h"

void dec_set_sign(s21_decimal *num, int sign) {
  sign = sign ? 1 : 0;
  dec_set_bit(num, index_dec_sign_bit, sign);
}