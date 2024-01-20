#ifndef S21_FUNC_ARITHMETIC_H_
#define S21_FUNC_ARITHMETIC_H_

#include "s21_structs.h"

/*main arithmetic functions*/
int s21_add(s21_decimal num1, s21_decimal num2, s21_decimal *res);
int s21_sub(s21_decimal num1, s21_decimal num2, s21_decimal *res);
int s21_mul(s21_decimal num1, s21_decimal num2, s21_decimal *res);
int s21_div(s21_decimal num1, s21_decimal num2, s21_decimal *res);

/*sub arithmetic functions*/
void sum_two_bit_any_index(s21_decimal num1, s21_decimal num2, s21_decimal *res,
                           int index1, int index2, int index_res,
                           int *next_digit);
void sum_two_bit(s21_decimal num1, s21_decimal num2, s21_decimal *res,
                 int index, int *next_digit);
int add_mantissa(s21_decimal num1, s21_decimal num2, s21_decimal *res);
int add_mantissa_with_twos_compliment(s21_decimal num1, s21_decimal num2,
                                      s21_decimal *res);
int base_add(s21_decimal num1, s21_decimal num2, s21_decimal *res);
int base_sub(s21_decimal num1, s21_decimal num2, s21_decimal *res);
int base_mul(s21_decimal num1, s21_decimal num2, s21_decimal *res);
int base_div(s21_decimal num1, s21_decimal num2, s21_decimal *res,
             s21_decimal *remainder);
void dec_div_ten(s21_decimal *value);

/* funcs using bit_decimal */
void add_mantissa_big(s21_decimal num1[2], s21_decimal num2[2],
                      s21_decimal res[2]);
int add_mantissa_big_with_twos_compliment(s21_decimal num1[2],
                                          s21_decimal num2[2],
                                          s21_decimal res[2]);
int big_dec_base_add(s21_decimal num1[2], s21_decimal num2[2],
                     s21_decimal res[2]);
int big_dec_base_sub(s21_decimal num1[2], s21_decimal num2[2],
                     s21_decimal res[2]);
void mul_proc(s21_decimal num1, s21_decimal num2, s21_decimal res_big[2]);
int big_dec_base_div(s21_decimal num1[2], s21_decimal num2[2],
                     s21_decimal res[2], s21_decimal remainder[2]);
void divide_by_ten_big_decimal(s21_decimal num[2], int *remainder);
int div_proc(s21_decimal num1, s21_decimal num2, s21_decimal *res);

#endif  // S21_FUNC_ARITHMETIC_H_