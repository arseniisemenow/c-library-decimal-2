#include "../s21_decimal.h"

int get_count_digits_in_decimal_mantissa(s21_decimal dest) {
  int count = 0;
  s21_decimal result = {0};
  s21_decimal remainder = {0};
  s21_decimal ten = LITERAL_DECIMAL_TEN;

  while (!dec_is_zero(dest)) {
    base_div(dest, ten, &result, &remainder);
    dec_copy(&dest, result);
    count++;
  }
  return count;
}

int get_bit_unsigned(const unsigned *number, int index) {
  return (*number & (1 << index)) > 0;
}

void delete_trailing_zeros_in_unsigned(unsigned int *mantissa) {
  int index = 0;
  while (get_bit_unsigned(mantissa, 0) == 0) {
    (*mantissa) >>= 1;
    index++;
  }
}

void delete_trailing_zeros_in_decimal(s21_decimal *number) {
  s21_decimal result = {0};
  s21_decimal remainder = {0};
  s21_decimal ten = LITERAL_DECIMAL_TEN;

  base_div(*number, ten, &result, &remainder);
  int scale = dec_get_scale(*number);

  while (remainder.bits[0] == 0 && scale-- > 0) {
    dec_mantissa_copy(&result, *number);
    base_div(*number, ten, &result, &remainder);
  }
  dec_set_scale(number, scale);
}

void adjust_decimal_for_float_conversion(s21_decimal *dest) {
  s21_decimal result = {0};
  s21_decimal remainder = {0};
  s21_decimal destCopy = *dest;
  s21_decimal ten = LITERAL_DECIMAL_TEN;
  s21_decimal one = LITERAL_DECIMAL_ONE;
  int count = get_count_digits_in_decimal_mantissa(*dest);
  int scale = dec_get_scale(*dest);
  int count_numbers_to_reduce = count - SAVING_NUMBERS_IN_FLOAT;

  for (int i = 0; i < count_numbers_to_reduce; i++) {
    base_div(destCopy, ten, &result, &remainder);
    dec_mantissa_copy(&destCopy, result);
    scale--;
  }

  if (remainder.bits[first_bit] >= BOUND_VALUE_TO_ROUND) {
    base_add(destCopy, one, &destCopy);
  }

  while (scale < 0 && count != get_count_digits_in_decimal_mantissa(destCopy)) {
    base_mul(destCopy, ten, &result);
    dec_mantissa_copy(&destCopy, result);
    scale++;
    dec_set_scale(&destCopy, scale);
  }

  dec_copy(dest, destCopy);
  dec_set_scale(dest, scale);
}

int get_scale_from_float_number_in_unsigned_representation(unsigned bits) {
  return (int)((bits << SIGN_BIT_NUMBER) >> MANTISSA_START_BIT_NUMBER) -
         FLOAT_EXP_MAX;
}

unsigned get_mantissa_float_number(unsigned bits) {
  return (bits << EXP_START_BIT_NUMBER) >> EXP_START_BIT_NUMBER;
}

unsigned change_binary_representation_from_float_to_unsigned(float number) {
  union floatUnsignedUnion converter;
  converter.floatValue = number;
  return converter.unsignedValue;
}

int is_zero_input(float src) { return src == 0.f; }

void handle_scale_for_float_number(int scale, s21_decimal mantissaDecimal,
                                   s21_decimal expDecimal, s21_decimal *dest) {
  if (scale < 0) {
    s21_div(mantissaDecimal, expDecimal, dest);
  } else {
    s21_mul(mantissaDecimal, expDecimal, dest);
  }
}

float get_float_sign(s21_decimal src) {
  return dec_get_sign(src) ? NEGATIVE_ONE_FLOAT : POSITIVE_ONE_FLOAT;
}

int handle_initial_error_condition_from_decimal_to_float(s21_decimal src,
                                                         float *dest) {
  int errorCode = error_code_conversion_no_error;
  int scale = dec_get_scale(src);
  if (dest == NULL) {
    errorCode = error_code_conversion_error;
  } else if (scale > MAX_SCALE) {
    *dest = 0;
    errorCode = error_code_conversion_error;
  }
  return errorCode;
}

int handle_initial_error_condition_from_int_to_decimal(int src,
                                                       s21_decimal *dst) {
  int error_code = error_code_conversion_no_error;
  if (dst && src != S21_INFINITY && src != S21_NAN) {
    error_code = error_code_conversion_no_error;
  } else {
    error_code = error_code_conversion_error;
  }
  return error_code;
}

int handle_initial_error_condition_from_float_to_decimal(float src) {
  int is_src_undefined = (src != src || src == POS_INF || src == NEG_INF);
  int is_src_in_the_bounds =
      (fabsf(src) >= DECIMAL_EXP_MIN && fabsf(src) <= DECIMAL_EXP_MAX);
  return is_src_undefined || !is_src_in_the_bounds;
}

int get_index_highest_bit_mantissa(s21_decimal *number) {
  int result = 0;
  for (int i = SIZE_OF_MANTISSA; i > 0 && !result; --i) {
    result = dec_get_bit(*number, i) ? i : 0;
  }
  return result;
}

int get_index_highest_bit_unsigned(unsigned int *number) {
  int result = 0;
  for (int i = SIZE_OF_INT_IN_BITS - 1; i >= 0 && !result; i--)
    result = get_bit_unsigned(number, i) ? i : 0;
  return result;
}