#ifndef S21_FUNC_COMPARISON_H_
#define S21_FUNC_COMPARISON_H_

/*main comparison functions*/
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int is_mantissa_equal(s21_decimal num1, s21_decimal num2);
int mantissa_is_greater(s21_decimal num1, s21_decimal num2);
int mantissa_is_greater_or_equal(s21_decimal num1, s21_decimal num2);

int big_dec_mantissa_is_equal(s21_decimal num1[2], s21_decimal num2[2]);
int big_dec_mantissa_is_greater(s21_decimal num1[2], s21_decimal num2[2]);
int big_dec_mantissa_is_greater_or_equal(s21_decimal num1[2],
                                         s21_decimal num2[2]);

#endif  // S21_FUNC_COMPARISON_H_