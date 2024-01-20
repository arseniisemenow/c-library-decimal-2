#include "../s21_decimal.h"

int is_negative_number_with_fractional_part(s21_decimal value,
                                            s21_decimal *result) {
  return (dec_get_sign(value) == 1 && s21_is_not_equal(value, *result));
}

void add_minus_one(s21_decimal *dest) {
  s21_decimal minus_one = LITERAL_DECIMAL_ONE;
  s21_negate(minus_one, &minus_one);
  s21_add(*dest, minus_one, dest);
}

void handle_negative_number_with_fractional_part(s21_decimal value,
                                                 s21_decimal *result) {
  if (is_negative_number_with_fractional_part(value, result)) {
    add_minus_one(result);
  }
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_truncate(value, result);
  handle_negative_number_with_fractional_part(value, result);
  return error_code_rounding_no_error;
}