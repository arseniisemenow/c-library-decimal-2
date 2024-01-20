#include "../s21_decimal.h"

int is_mantissa_equal(s21_decimal num1, s21_decimal num2) {
  int res = return_value_comparison_true;
  for (int i = 0; i <= third_bit; i++) {
    res &= (num1.bits[i] == num2.bits[i]);
  }
  return res;
}

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int res = return_value_comparison_true;
  int sign1 = dec_get_sign(num1);
  int sign2 = dec_get_sign(num2);
  int scale_num1 = dec_get_scale(num1);
  int scale_num2 = dec_get_scale(num2);

  if (sign1 == sign2) {
    if (scale_num1 != scale_num2) {
      dec_normalization(num1, num2, &num1, &num2);
    }
    res = is_mantissa_equal(num1, num2);
  } else if (dec_is_zero(num1) && dec_is_zero(num2)) {
    res = return_value_comparison_true;
  } else {
    res = return_value_comparison_false;
  }

  return res;
}

int big_dec_mantissa_is_equal(s21_decimal num1[2], s21_decimal num2[2]) {
  int res = return_value_comparison_true;
  for (int i = 0; i < header_bit; i++) {
    res &= ((num1[0]).bits[i] == (num2[0]).bits[i]);
  }
  for (int i = 0; i < header_bit; i++) {
    res &= ((num1[1]).bits[i] == (num2[1]).bits[i]);
  }
  return res;
}
