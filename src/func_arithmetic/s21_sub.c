#include "../s21_decimal.h"

int base_sub(s21_decimal num1, s21_decimal num2, s21_decimal *res) {
  int sign_num2 = dec_get_sign(num2);
  dec_set_sign(&num2, sign_num2 ? 0 : 1);
  return add_mantissa_with_twos_compliment(num1, num2, res);
}

int s21_sub(s21_decimal num1, s21_decimal num2, s21_decimal *res) {
  if (res == NULL) {
    return error_code_null_pointer;
  }
  dec_init_num(res);
  dec_normalization(num1, num2, &num1, &num2);
  dec_set_scale(res, dec_get_scale(num1));
  return base_sub(num1, num2, res);
}

/* big decimal */

int big_dec_base_sub(s21_decimal num1[2], s21_decimal num2[2],
                     s21_decimal res[2]) {
  int sign_num2 = big_dec_getsign(num2);
  big_dec_setsign(num2, sign_num2 ? 0 : 1);
  int error_code = big_dec_base_add(num1, num2, res);
  big_dec_setsign(num2, sign_num2);
  return error_code;
}