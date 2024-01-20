#include "../s21_decimal.h"

int big_dec_getbit(s21_decimal num[2], int index) {
  if (index < 0 || index >= SIZE_OF_MANTISSA * 2) return err_incorrect_index;
  int big_dec_index = index / SIZE_OF_MANTISSA;
  int dec_index = index % SIZE_OF_MANTISSA;
  return dec_get_bit(num[big_dec_index], dec_index);
}
