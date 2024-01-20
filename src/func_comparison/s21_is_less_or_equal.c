#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return !s21_is_greater(num1, num2);
}
