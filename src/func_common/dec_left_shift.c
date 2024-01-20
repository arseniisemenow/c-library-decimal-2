#include "../s21_decimal.h"

int dec_left_shift(s21_decimal *num, int shift) {
  if (shift < 0) shift = 0;

  int error_code = error_code_no_err;
  int sign = dec_get_sign(*num);
  int dec_len = dec_num_len(*num);
  if ((dec_len + shift) > SIZE_OF_MANTISSA) {
    if (sign) {
      error_code = error_code_arithmetic_too_small_or_negative_inf;
    } else {
      error_code = error_code_arithmetic_too_large_or_inf;
    }
  }

  for (int i = SIZE_OF_MANTISSA - 1; i >= shift; i--) {
    int bit = dec_get_bit(*num, i - shift);
    dec_set_bit(num, i, bit);
  }
  for (int i = 0; i < shift; i++) {
    dec_set_bit(num, i, 0);
  }

  return error_code;
}