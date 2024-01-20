#ifndef S21_STRUCTS_H_
#define S21_STRUCTS_H_

#include "s21_constants_num.h"

typedef enum {
  index_dec_header_start_exp_bits = INDEX_DEC_HEADER_START_SCALE_BITS,
  index_dec_header_end_exp_bits = INDEX_DEC_HEADER_END_SCALE_BITS,
  index_dec_sign_bit = INDEX_DEC_SIGN_BITS
} index_dec;

typedef enum {
  index_big_dec_sign_bit = INDEX_BIG_DEC_SIGN_BITS,
} index_big_dec;

typedef enum {
  first_bit = 0,
  second_bit = 1,
  third_bit = 2,
  header_bit = 3
} index_dec_bit_names;

typedef enum {
  error_code_no_err = 0,
  err_incorrect_index = 1 << 0,
  error_code_num_is_too_small_or_great = 1 << 1,
  error_code_scale_is_too_small_or_great = 1 << 2,
  error_code_loss_info = 1 << 3,
  error_code_incorrect_number_system = 1 << 4,
  error_code_null_pointer = 1 << 5,
} error_code;

/*return constants for main functions*/
typedef enum {
  error_code_arithmetic_no_err = 0,
  error_code_arithmetic_too_large_or_inf = 1,
  error_code_arithmetic_too_small_or_negative_inf = 2,
  error_code_arithmetic_div_by_zero = 3
} error_code_arithmetic;

typedef enum {
  return_value_comparison_false = 0,
  return_value_comparison_true = 1
} return_value_comparison;

typedef enum {
  error_code_conversion_no_error = 0,
  error_code_conversion_error = 1
} error_code_conversion;

typedef enum {
  error_code_rounding_no_error = 0,
  error_code_rounding_error = 1
} error_code_rounding;

typedef struct {
  unsigned bits[NUMBER_OF_BITS_IN_DEC];
} s21_decimal;

union floatUnsignedUnion {
  float floatValue;
  unsigned unsignedValue;
};

#endif  // S21_STRUCTS_H_