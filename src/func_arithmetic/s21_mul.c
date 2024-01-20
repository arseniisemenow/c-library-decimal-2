#include "../s21_decimal.h"
void bank_rounding_in_multiplication_process(int penultimate_digit,
                                             int last_digit,
                                             s21_decimal res_big[2]) {
  s21_decimal one_big[2] = LITERAL_BIG_DECIMAL_ONE;
  if (penultimate_digit % 2 == 0 && last_digit > 5) {
    add_mantissa_big(res_big, one_big, res_big);
  } else if (penultimate_digit % 2 == 1 && last_digit >= 5) {
    add_mantissa_big(res_big, one_big, res_big);
  }
}

int base_mul(s21_decimal num1, s21_decimal num2, s21_decimal *res) {
  dec_set_zero(res);

  int shift = 0;
  int error_code = error_code_arithmetic_no_err;
  int error_var_temp1 = error_code_arithmetic_no_err;
  int error_var_temp2 = error_code_arithmetic_no_err;
  for (int i = 0; i < SIZE_OF_MANTISSA && !error_code; i++) {
    int bit = dec_get_bit(num2, i);
    if (bit) {
      error_var_temp1 = dec_left_shift(&num1, i - shift);
      shift = i;
      error_var_temp2 = base_add(num1, *res, res);

      if (error_var_temp1) {
        error_code = error_var_temp1;
      } else if (error_var_temp2) {
        error_code = error_var_temp2;
      }
    }
  }

  int sign1 = dec_get_sign(num1);
  int sign2 = dec_get_sign(num2);
  int sign = sign1 ^ sign2;
  dec_set_sign(res, sign);

  return error_code;
}

void mul_proc(s21_decimal num1, s21_decimal num2, s21_decimal res_big[2]) {
  s21_decimal divisor = LITERAL_DECIMAL_2_IN_POWER_OF_48;

  s21_decimal num1_quot = {0};
  s21_decimal num2_quot = {0};
  s21_decimal num1_rem = {0};
  s21_decimal num2_rem = {0};
  s21_decimal parts[4] = {0};

  base_div(num1, divisor, &num1_quot, &num1_rem);
  base_div(num2, divisor, &num2_quot, &num2_rem);

  base_mul(num1_quot, num2_quot, &(parts[0]));
  base_mul(num1_quot, num2_rem, &(parts[1]));
  base_mul(num1_rem, num2_quot, &(parts[2]));
  base_mul(num1_rem, num2_rem, &(parts[3]));

  s21_decimal part1_big[2] = {parts[0], {{0, 0, 0, 0}}};
  s21_decimal part2_big[2] = {parts[1], {{0, 0, 0, 0}}};
  s21_decimal part3_big[2] = {parts[2], {{0, 0, 0, 0}}};
  s21_decimal part4_big[2] = {parts[3], {{0, 0, 0, 0}}};

  big_dec_left_shift(part1_big, SIZE_OF_MANTISSA);
  big_dec_left_shift(part2_big, SIZE_OF_MANTISSA / 2);
  big_dec_left_shift(part3_big, SIZE_OF_MANTISSA / 2);

  add_mantissa_big(part1_big, part2_big, res_big);
  add_mantissa_big(res_big, part3_big, res_big);
  add_mantissa_big(res_big, part4_big, res_big);
}

int s21_mul(s21_decimal num1, s21_decimal num2, s21_decimal *res) {
  if (res == NULL) {
    return error_code_null_pointer;
  }
  dec_init_num(res);
  int error_code = error_code_arithmetic_no_err;

  int sign1 = dec_get_sign(num1);
  int sign2 = dec_get_sign(num2);
  int sign = sign1 ^ sign2;

  s21_decimal res_big[2] = {0};
  mul_proc(num1, num2, res_big);

  int scale = dec_get_scale(num1) + dec_get_scale(num2);
  int last_digit = 0;
  while ((!dec_is_zero(res_big[1]) && scale > 0) || scale > MAX_SCALE) {
    divide_by_ten_big_decimal(res_big, &last_digit);
    scale--;
  }
  int penultimate_digit = big_dec_get_last_digit(res_big);

  bank_rounding_in_multiplication_process(penultimate_digit, last_digit,
                                          res_big);

  dec_set_scale(&res_big[0], scale);
  dec_copy(res, res_big[0]);
  dec_set_sign(res, sign);

  if (!scale && !dec_is_zero(res_big[1]) && !sign) {
    error_code = error_code_arithmetic_too_large_or_inf;
  } else if (!scale && !dec_is_zero(res_big[1]) && sign) {
    error_code = error_code_arithmetic_too_small_or_negative_inf;
  }
  return error_code;
}