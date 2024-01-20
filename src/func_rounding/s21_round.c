#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal five = LITERAL_DECIMAL_FIVE;
  dec_set_scale(&five, 1);
  if (dec_get_scale(value) != 0) {
    s21_add(value, five, result);
    s21_truncate(*result, result);
  } else {
    (*result) = value;
  }
  return 0;
}
