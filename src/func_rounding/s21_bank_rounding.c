#include "../s21_decimal.h"

void s21_bank_rounding(s21_decimal *num, int penultimate_digit,
                       int last_digit) {
  s21_decimal one = LITERAL_DECIMAL_ONE;
  s21_decimal num_temp = LITERAL_DECIMAL_ZERO;
  int error_code = error_code_arithmetic_no_err;
  dec_copy(&num_temp, *num);
  if (penultimate_digit % 2 == 0 && last_digit > 5) {
    if (!dec_get_sign(*num)) {
      error_code = base_add(num_temp, one, &num_temp);
      if (!error_code) {
        base_add(*num, one, num);
      }
    } else {
      error_code = base_sub(num_temp, one, &num_temp);
      if (!error_code) {
        base_sub(*num, one, num);
      }
    }
  } else if (penultimate_digit % 2 == 1 && last_digit >= 5) {
    if (!dec_get_sign(*num)) {
      error_code = base_add(num_temp, one, &num_temp);
      if (!error_code) {
        base_add(*num, one, num);
      }
    } else {
      error_code = base_sub(num_temp, one, &num_temp);
      if (!error_code) {
        base_sub(*num, one, num);
      }
    }
  }
}