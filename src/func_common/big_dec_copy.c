#include "../s21_decimal.h"

void big_dec_copy(s21_decimal dest[2], s21_decimal src[2]) {
  for (int i = 0; i < NUMBER_OF_BITS_IN_DEC; i++) {
    dest[0].bits[i] = src[0].bits[i];
  }
  for (int i = 0; i < NUMBER_OF_BITS_IN_DEC; i++) {
    dest[1].bits[i] = src[1].bits[i];
  }
}