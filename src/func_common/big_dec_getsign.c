#include "../s21_decimal.h"

int big_dec_getsign(s21_decimal num[2]) {
  return dec_get_bit(num[1], index_dec_sign_bit);
}
