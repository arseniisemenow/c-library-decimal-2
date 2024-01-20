#include "../s21_decimal.h"

int big_dec_get_last_digit(s21_decimal num[2]) {
  s21_decimal temp_big[2] = {0};
  big_dec_copy(temp_big, num);
  int result = 0;
  divide_by_ten_big_decimal(temp_big, &result);
  return result;
}