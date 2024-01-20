#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dest) {
  int error_code = error_code_conversion_no_error;
  error_code = handle_initial_error_condition_from_int_to_decimal(src, dest);
  if (error_code) {
    return error_code;
  }
  dec_set_zero(dest);
  int sign = src < 0;
  dest->bits[first_bit] = sign ? -src : src;
  dec_set_sign(dest, sign);
  return error_code;
}
