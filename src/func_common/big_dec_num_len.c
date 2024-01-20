#include "../s21_decimal.h"

int big_dec_num_len(s21_decimal num_big[2]) {
  int res = 0;
  for (int i = 0; i < 2 * SIZE_OF_MANTISSA; i++) {
    if (big_dec_getbit(num_big, i)) {
      res = i;
    }
  }
  return res + 1;
}