#include "../s21_decimal.h"

void print_dec_bin(s21_decimal num) {
  for (int i = 0; i < SIZE_OF_DEC; i++) {
    int byte_index = i / SIZE_OF_INT_IN_BITS;
    int bit_index = i % SIZE_OF_INT_IN_BITS;
    if (bit_index == 0) putchar('{');
    if (byte_index == 3 && bit_index == 16) putchar('|');
    putchar(dec_get_bit(num, i) + '0');
    if (byte_index == 3 && bit_index == 23) putchar('|');
    if (bit_index == SIZE_OF_INT_IN_BITS - 1) putchar('}');
  }
  putchar('\n');
}

void print_dec_bin_num(s21_decimal num) {
  for (int i = SIZE_OF_MANTISSA - 1; i >= 0; i--) {
    putchar(dec_get_bit(num, i) + '0');
  }
  putchar('-');
  for (int i = SIZE_OF_DEC - 1; i >= SIZE_OF_MANTISSA; i--) {
    int byte_index = i / SIZE_OF_INT_IN_BITS;
    int bit_index = i % SIZE_OF_INT_IN_BITS;
    if (byte_index == 3 && bit_index == 23) putchar('|');
    putchar(dec_get_bit(num, i) + '0');
    if (byte_index == 3 && bit_index == 16) putchar('|');
  }
  putchar('\n');
}

void print_dec_bin_ptr(s21_decimal *num) {
  for (int i = 0; i < SIZE_OF_DEC; i++) {
    int byte_index = i / SIZE_OF_INT_IN_BITS;
    int bit_index = i % SIZE_OF_INT_IN_BITS;
    if (bit_index == 0) putchar('{');
    if (byte_index == 3 && bit_index == 16) putchar('|');
    putchar(dec_get_bit(*num, i) + '0');
    if (byte_index == 3 && bit_index == 23) putchar('|');
    if (bit_index == SIZE_OF_INT_IN_BITS - 1) putchar('}');
  }
  putchar('\n');
}

void print_dec_uint(s21_decimal num) {
  printf("%u, %u, %u, %u, %u\n", num.bits[0], num.bits[1], num.bits[2],
         dec_get_scale(num), dec_is_zero(num) ? 0 : dec_get_sign(num));
}

int dec_num_to_str(char *dest, s21_decimal num, int base) {
  int error_code = error_code_no_err;
  if (base != 10) return error_code_incorrect_number_system;

  if (dec_get_sign(num) && !dec_is_zero(num)) {
    *dest++ = '-';
    dec_set_sign(&num, 0);
  }

  int scale = dec_get_scale(num);
  int num_len = dec_num_len_any(num, base);
  num_len = (scale > 0) ? scale >= num_len ? scale + 2 : num_len + 1 : num_len;
  s21_decimal radix = {{(unsigned)base, 0, 0, 0}};

  s21_decimal remainder = {0};
  for (int i = 0; i < num_len; i++) {
    if (i == scale && scale) {
      dest[num_len - 1 - i] = '.';
    } else {
      base_div(num, radix, &num, &remainder);
      dest[num_len - 1 - i] = remainder.bits[0] + '0';
    }
  }
  dest[num_len] = '\0';
  return error_code;
}

void print_dec_num(s21_decimal num) {
  char str[100];
  dec_num_to_str(str, num, 10);
  printf("%s\n", str);
}

void print_big_dec_bin_num(s21_decimal num[2]) {
  for (int i = SIZE_OF_MANTISSA - 1; i >= 0; i--) {
    putchar(dec_get_bit(num[1], i) + '0');
  }
  for (int i = SIZE_OF_MANTISSA - 1; i >= 0; i--) {
    putchar(dec_get_bit(num[0], i) + '0');
  }
  // putchar('\n');
  // for (int i = SIZE_OF_DEC - 1; i >= SIZE_OF_MANTISSA; i--) {
  //   int byte_index = i / SIZE_OF_INT_IN_BITS;
  //   int bit_index = i % SIZE_OF_INT_IN_BITS;
  //   if (byte_index == 3 && bit_index == 23) putchar('|');
  //   putchar(dec_get_bit(num[1], i) + '0');
  //   if (byte_index == 3 && bit_index == 16) putchar('|');
  // }
  printf("-%c\n", dec_get_bit(num[1], index_dec_sign_bit) + '0');
}

void print_big_dec_bin_num_ptr(s21_decimal (*num)[2]) {
  for (int i = SIZE_OF_MANTISSA - 1; i >= 0; i--) {
    putchar(dec_get_bit((*num)[1], i) + '0');
  }
  for (int i = SIZE_OF_MANTISSA - 1; i >= 0; i--) {
    putchar(dec_get_bit((*num)[0], i) + '0');
  }

  putchar('\n');
}

// Finds the number of digits in different number systems

int dec_num_len_any(s21_decimal num, int base) {
  if (dec_get_sign(num)) dec_set_sign(&num, 0);

  s21_decimal radix = {{(unsigned)base, 0, 0, 0}};
  int number_of_digit = 0;
  s21_decimal temp_num = LITERAL_DECIMAL_ONE;
  int error_code = false;

  while (mantissa_is_greater_or_equal(num, temp_num) && !error_code) {
    number_of_digit++;
    error_code = base_mul(temp_num, radix, &temp_num);
  }

  if (number_of_digit == 0) number_of_digit = 1;

  return number_of_digit;
}
