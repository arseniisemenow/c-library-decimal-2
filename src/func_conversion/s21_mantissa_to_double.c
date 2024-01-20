#include "../s21_decimal.h"

double s21_mantissa_to_double(s21_decimal src) {
  double result = 0;
  double scale = 1;
  for (int i = 0; i < NUMBER_OF_BITS_IN_MANTISSA; i++) {
    result += ((double)src.bits[i] * scale);
    scale *= UNSIGNED_MAX;
  }
  return result;
}