#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dest) {
  dec_set_zero(dest);
  int flag_invalid_input =
      handle_initial_error_condition_from_float_to_decimal(src);
  int flag_zero_input = is_zero_input(src);

  if (flag_invalid_input) return error_code_conversion_error;
  if (flag_zero_input) return error_code_conversion_no_error;

  unsigned bits = change_binary_representation_from_float_to_unsigned(src);

  int scale = get_scale_from_float_number_in_unsigned_representation(bits);
  unsigned mantissa = get_mantissa_float_number(bits);

  SET_BIT(mantissa, FIRST_BIT_NUMBER_IN_MANTISSA);
  delete_trailing_zeros_in_unsigned(&mantissa);
  scale -= get_index_highest_bit_unsigned(&mantissa);

  s21_decimal mantissa_decimal = {{mantissa, 0, 0, 0}};
  s21_decimal exp_decimal = LITERAL_DECIMAL_ONE;
  dec_left_shift(&exp_decimal, abs(scale));
  handle_scale_for_float_number(scale, mantissa_decimal, exp_decimal, dest);

  int sign = src < ZERO_FLOAT;
  adjust_decimal_for_float_conversion(dest);
  delete_trailing_zeros_in_decimal(dest);
  dec_set_sign(dest, sign);
  return error_code_conversion_no_error;
}