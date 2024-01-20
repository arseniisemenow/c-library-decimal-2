#ifndef S21_MACROS_H_
#define S21_MACROS_H_

#include <stdint.h>

#define SET_BIT(num, index) (num |= 1 << index)
#define RESET_BIT(num, index) (num &= ~(1 << index))

#define is_fin(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
#define TRICKY_LOOP \
  while (pos >= 0 && int_str[pos] == '0') int_str[pos--] = '\0';

#endif  // S21_MACROS_H_