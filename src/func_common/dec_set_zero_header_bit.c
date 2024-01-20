#include "../s21_decimal.h"

void dec_set_zero_header_bit(s21_decimal *num) { num->bits[header_bit] = 0; }