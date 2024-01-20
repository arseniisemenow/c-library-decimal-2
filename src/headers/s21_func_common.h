#ifndef S21_FUNC_COMMON_H_
#define S21_FUNC_COMMON_H_

/*binary operations*/
int dec_get_bit(s21_decimal num, int index);

void dec_set_bit(s21_decimal *num, int index, int bit);

int dec_get_scale(s21_decimal num);

int dec_set_scale(s21_decimal *num, int scale);

int dec_get_sign(s21_decimal num);

void dec_set_sign(s21_decimal *num, int sign);

int dec_left_shift(s21_decimal *num, int shift);

void dec_right_shift(s21_decimal *num, int shift);

int big_dec_getbit(s21_decimal num[2], int index);

void big_dec_setbit(s21_decimal num[2], int index, int bit);

int big_dec_getsign(s21_decimal num[2]);

void big_dec_setsign(s21_decimal num[2], int sign);

bool big_dec_is_zero(s21_decimal num_big[2]);

void big_dec_init(s21_decimal num_big[2]);

void big_dec_left_shift(s21_decimal num[2], int shift);

void big_dec_right_shift(s21_decimal num[2], int shift);

void big_dec_twos_compliment(s21_decimal num[2]);

int big_dec_num_len(s21_decimal num_big[2]);

/*other functions*/
s21_decimal dec_define(unsigned bit1, unsigned bit2, unsigned bit3, int scale,
                       int sign);

void dec_set_zero(s21_decimal *num);

bool dec_is_zero(s21_decimal num);

bool is_mantissa_full(s21_decimal num);

void dec_copy(s21_decimal *dest, s21_decimal src);

void dec_mantissa_copy(s21_decimal *dest, s21_decimal src);

s21_decimal dec_twos_complement(s21_decimal num);

int dec_get_last_digit(s21_decimal num);

int normalization_process(s21_decimal num1, s21_decimal num2,
                          s21_decimal *num1_norm, s21_decimal *num2_norm);

int dec_normalization(s21_decimal num1, s21_decimal num2,
                      s21_decimal *num1_norm, s21_decimal *num2_norm);

int dec_num_len(s21_decimal num);

s21_decimal get_powered_of_ten(int scale);

int get_len_ten_powered(int scale);

void dec_init_num(s21_decimal *num);

int get_bin_float_exp(float src);

int get_bit_float(float num, int index_bit);

void dec_set_zero_header_bit(s21_decimal *num);

void big_dec_copy(s21_decimal dest[2], s21_decimal src[2]);

int big_dec_get_last_digit(s21_decimal num[2]);

void tr_zeroes(unsigned int *str_num, int *scale);

#endif  // S21_FUNC_COMMON_H_