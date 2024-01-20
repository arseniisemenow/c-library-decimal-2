#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dest) {
  int error_code =
      handle_initial_error_condition_from_decimal_to_float(src, dest);

  int scale = dec_get_scale(src);
  float sign = get_float_sign(src);

  double temp_dest = 0;

  for (int i = 0; i < get_index_highest_bit_mantissa(&src) + 1; i++) {
    temp_dest += pow(2, i) * dec_get_bit(src, i);
  }

  if (scale > 0) {
    temp_dest /= pow(10, scale);
  }
  *dest = (float)(temp_dest)*sign;
  return error_code;
}