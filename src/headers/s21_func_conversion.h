#ifndef S21_FUNC_CONVERSION_H_
#define S21_FUNC_CONVERSION_H_

/*main conversion functions*/
int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_from_decimal_to_float(s21_decimal src, float *dst);

double s21_mantissa_to_double(s21_decimal src);

int s21_from_float_string(int whole, float fract, s21_decimal *value);

/* big decimal */

void s21_from_decimal_to_big_decimal(s21_decimal num, s21_decimal num_big[2]);

/* aux functions */
int get_count_digits_in_decimal_mantissa(s21_decimal dest);

int get_bit_unsigned(const unsigned *number, int index);

void delete_trailing_zeros_in_unsigned(unsigned int *mantissa);

void delete_trailing_zeros_in_decimal(s21_decimal *number);

void adjust_decimal_for_float_conversion(s21_decimal *dest);

int get_scale_from_float_number_in_unsigned_representation(unsigned bits);

unsigned get_mantissa_float_number(unsigned bits);

unsigned change_binary_representation_from_float_to_unsigned(float number);

int is_zero_input(float src);

void handle_scale_for_float_number(int scale, s21_decimal mantissaDecimal,
                                   s21_decimal expDecimal, s21_decimal *dest);

float get_float_sign(s21_decimal src);

int handle_initial_error_condition_from_decimal_to_float(s21_decimal src,
                                                         float *dest);
int handle_initial_error_condition_from_int_to_decimal(int src,
                                                       s21_decimal *dst);

int handle_initial_error_condition_from_float_to_decimal(float src);

int get_index_highest_bit_mantissa(s21_decimal *number);

int get_index_highest_bit_unsigned(unsigned int *number);

#endif  // S21_FUNC_CONVERSION_H_