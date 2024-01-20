#include "../s21_decimal.h"

void dec_div_ten(s21_decimal *value) {
  unsigned long long int last = value->bits[2];
  unsigned int remainder = 0;
  for (int i = 2; i >= 0; i--) {
    remainder = last % 10;
    value->bits[i] = last / 10;
    last = remainder * (UNSIGNED_MAX) + value->bits[i - 1];
  }
}