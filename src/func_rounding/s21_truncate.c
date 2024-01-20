#include "../s21_decimal.h"
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int scale = dec_get_scale(value);
  *result = value;
  while (scale > 0) {
    dec_div_ten(result);
    scale--;
  }
  dec_set_scale(result, 0);
  return 0;
}
