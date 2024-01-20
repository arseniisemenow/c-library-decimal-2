#include "../s21_decimal.h"

int dec_get_scale(s21_decimal num) {
  return (int)(num.bits[header_bit] >> index_dec_header_start_exp_bits) &
         SCALE_MASK;
}
