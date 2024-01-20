#include "../s21_decimal.h"

int dec_set_scale(s21_decimal *num, int scale) {
  if (scale < 0 || scale > SCALE_MASK) {
    return error_code_scale_is_too_small_or_great;
  }
  num->bits[header_bit] &= SCALE_CLR_MASK;
  num->bits[header_bit] |= scale << index_dec_header_start_exp_bits;

  return error_code_no_err;
}