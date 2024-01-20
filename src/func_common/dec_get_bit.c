#include "../s21_decimal.h"

int dec_get_bit(s21_decimal num, int index) {
  if (index < 0 || index >= SIZE_OF_DEC) return err_incorrect_index;
  int byte_index = index / SIZE_OF_INT_IN_BITS;
  int bit_index = index % SIZE_OF_INT_IN_BITS;
  return (num.bits[byte_index] & (1 << bit_index)) > 0;
}
