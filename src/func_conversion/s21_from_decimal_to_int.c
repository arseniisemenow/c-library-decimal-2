#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dest) {
  int error_code = s21_truncate(src, &src);
  int sign = dec_get_sign(src);
  *dest = 0;
  if (!error_code) {
    int is_number_out_of_the_bounds;
    is_number_out_of_the_bounds = (
#ifdef __linux__
        (sign == 0 && src.bits[first_bit] > (unsigned)INT_MAX) ||
        (sign == 1 && src.bits[first_bit] > (unsigned)INT_MIN)
#else
        (sign == 0 && src.bits[first_bit] > (unsigned)INT32_MAX) ||
        (sign == 1 && src.bits[first_bit] > (unsigned)INT32_MIN)
#endif
    );
    if (src.bits[second_bit] != 0 || src.bits[third_bit] != 0 ||
        is_number_out_of_the_bounds) {
      error_code = error_code_conversion_error;
    } else {
      *dest = (int)src.bits[first_bit];
      *dest = sign == 0 ? *dest : -(*dest);
    }
  }
  return error_code;
}
