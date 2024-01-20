#include "../s21_decimal.h"

void dec_set_bit(s21_decimal *num, int index, int bit) {
  bit = bit ? 1 : 0;
  if (index >= 0 && index <= SIZE_OF_DEC) {
    int byte_index = index / SIZE_OF_INT_IN_BITS;
    int bit_index = index % SIZE_OF_INT_IN_BITS;
    if (bit) {
      SET_BIT(num->bits[byte_index], bit_index);
    } else {
      RESET_BIT(num->bits[byte_index], bit_index);
    }
  }
}
