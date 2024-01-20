#ifndef S21_FUNC_DEVELOP_H_
#define S21_FUNC_DEVELOP_H_

#include "s21_structs.h"

/*
Develop functions
These features should not be in the final version
*/

int dec_num_len_any(s21_decimal num, int base);
int dec_num_to_str(char *dest, s21_decimal num, int base);
void print_dec_num(s21_decimal num);
void print_dec_bin(s21_decimal num);
void print_dec_bin_num(s21_decimal num);
void print_dec_uint(s21_decimal num);
void print_big_dec_bin_num(s21_decimal num[2]);
void print_big_dec_bin_num_ptr(s21_decimal (*num)[2]);
void print_dec_bin_ptr(s21_decimal *num);

#endif  // S21_FUNC_DEVELOP_H_