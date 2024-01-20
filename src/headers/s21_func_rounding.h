#ifndef S21_FUNC_ROUNDING_H_
#define S21_FUNC_ROUNDING_H_

/*main rounding functions*/
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
void s21_bank_rounding(s21_decimal *num, int penultimate_digit, int last_digit);

#endif  // S21_FUNC_ROUNDING_H_