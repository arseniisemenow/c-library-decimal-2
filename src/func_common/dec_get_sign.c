#include "../s21_decimal.h"

int dec_get_sign(s21_decimal num) {
  return dec_get_bit(num, index_dec_sign_bit);
}
