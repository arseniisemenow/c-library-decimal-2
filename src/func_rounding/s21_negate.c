#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  dec_set_sign(result, !dec_get_sign(value));
  return 0;
}