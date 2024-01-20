#include "../s21_decimal.h"

void dec_init_num(s21_decimal* num) {
  for (int i = 0; i < SIZE_OF_DEC; i++) {
    dec_set_bit(num, i, 0);
  }
}