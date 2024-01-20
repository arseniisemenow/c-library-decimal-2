#include "../s21_decimal.h"

void bank_rounding_in_normalization_process(s21_decimal *num1_norm,
                                            s21_decimal *num2_norm,
                                            s21_decimal *temp,
                                            s21_decimal *remainder) {
  s21_decimal ten = LITERAL_DECIMAL_TEN;

  int is_possible_to_mul = !(base_mul(*num1_norm, ten, temp));
  if (!is_possible_to_mul) {
    unsigned last_digit = remainder->bits[0];
    int penultimate_digit = dec_get_last_digit(*num2_norm);
    s21_decimal term = LITERAL_DECIMAL_ONE;
    if (penultimate_digit % 2 == 0 && last_digit > 5) {
      if (!dec_get_sign(*num2_norm)) {
        base_add(*num2_norm, term, num2_norm);
      } else {
        base_sub(*num2_norm, term, num2_norm);
      }
    }
    if (penultimate_digit % 2 == 1 && last_digit >= 5) {
      if (!dec_get_sign(*num2_norm)) {
        base_add(*num2_norm, term, num2_norm);
      } else {
        base_sub(*num2_norm, term, num2_norm);
      }
    }
  }
}

int normalization_process(s21_decimal num1, s21_decimal num2,
                          s21_decimal *num1_norm, s21_decimal *num2_norm) {
  int error_code = error_code_no_err;

  dec_copy(num1_norm, num1);
  dec_copy(num2_norm, num2);

  int scale1 = dec_get_scale(num1);
  int scale2 = dec_get_scale(num2);

  s21_decimal remainder = {0};
  s21_decimal temp = {0};
  s21_decimal ten = LITERAL_DECIMAL_TEN;

  while (scale1 != scale2) {
    int is_possible_to_mul = !(base_mul(*num1_norm, ten, &temp));
    if (is_possible_to_mul) {
      base_mul(*num1_norm, ten, num1_norm);
      dec_set_scale(num1_norm, ++scale1);
    } else {
      base_div(*num2_norm, ten, num2_norm, &remainder);
      dec_set_scale(num2_norm, --scale2);
      error_code = error_code_loss_info;
    }
  }

  bank_rounding_in_normalization_process(num1_norm, num2_norm, &temp,
                                         &remainder);

  return error_code;
}

int dec_normalization(s21_decimal num1, s21_decimal num2,
                      s21_decimal *num1_norm, s21_decimal *num2_norm) {
  int error_code = error_code_no_err;
  int scale1 = dec_get_scale(num1);
  int scale2 = dec_get_scale(num2);
  if (scale1 <= scale2) {
    error_code = normalization_process(num1, num2, num1_norm, num2_norm);
  } else {
    error_code = normalization_process(num2, num1, num2_norm, num1_norm);
  }
  return error_code;
}