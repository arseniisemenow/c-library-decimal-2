#ifndef S21_CONSTANTS_NUM_H_
#define S21_CONSTANTS_NUM_H_

#define INT_MAX (2147483647)
#define INT_MIN (2147483648)
#define UNSIGNED_MAX (4294967296)

#define S21_INFINITY (1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)

#define NUMBER_OF_BITS_IN_DEC (4)
#define NUMBER_OF_BITS_IN_MANTISSA (3)
#define NUMBER_OF_BITS_IN_BYTE (8)
#define SIZE_OF_INT_IN_BITS \
  ((int)(sizeof(int) * NUMBER_OF_BITS_IN_BYTE))  // Usually 32
#define SIZE_OF_MANTISSA \
  ((int)(NUMBER_OF_BITS_IN_MANTISSA * SIZE_OF_INT_IN_BITS))  // Usually 96
#define SIZE_OF_DEC \
  ((int)(NUMBER_OF_BITS_IN_DEC * SIZE_OF_INT_IN_BITS))  // Usually 128
#define MAX_SCALE (28)
#define SCALE_MASK 0xFF
#define SCALE_CLR_MASK 0xFF00FFFF
#define INDEX_DEC_HEADER_START_SCALE_BITS (16)
#define INDEX_DEC_HEADER_END_SCALE_BITS (23)
#define INDEX_DEC_SIGN_BITS (127)
#define INDEX_BIG_DEC_SIGN_BITS (255)

#define SAVING_NUMBERS_IN_FLOAT (7)
#define BOUND_VALUE_TO_ROUND (5)
#define SIGN_BIT_NUMBER (1)
#define MANTISSA_START_BIT_NUMBER (24)
#define FLOAT_EXP_MAX (127)
#define EXP_START_BIT_NUMBER (9)
#define NEGATIVE_ONE_FLOAT (-1.f)
#define POSITIVE_ONE_FLOAT (1.f)
#define ZERO_FLOAT (0.f)

#define POS_INF (1.0 / +0.0)
#define NEG_INF (1.0 / -0.0)
#define DECIMAL_EXP_MIN (1.0e-28)
#define DECIMAL_EXP_MAX (7.922816e+28)
#define FIRST_BIT_NUMBER_IN_MANTISSA (MANTISSA_START_BIT_NUMBER - 1)

#define LITERAL_DECIMAL_ZERO \
  {                          \
    { 0, 0, 0, 0 }           \
  }

#define LITERAL_DECIMAL_ONE \
  {                         \
    { 1, 0, 0, 0 }          \
  }

#define LITERAL_DECIMAL_FIVE \
  {                          \
    { 5, 0, 0, 0 }           \
  }

#define LITERAL_DECIMAL_TEN \
  {                         \
    { 10, 0, 0, 0 }         \
  }

#define LITERAL_DECIMAL_MAX                   \
  {                                           \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 } \
  }

// 2^48
#define LITERAL_DECIMAL_2_IN_POWER_OF_48 \
  {                                      \
    { 0, 0x10000, 0, 0 }                 \
  }

#define LITERAL_DECIMAL_FULL                           \
  {                                                    \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF } \
  }

#define LITERAL_BIG_DECIMAL_ONE \
  { LITERAL_DECIMAL_ONE, LITERAL_DECIMAL_ZERO }

#define LITERAL_BIG_DECIMAL_ZERO \
  { LITERAL_DECIMAL_ZERO, LITERAL_DECIMAL_ZERO }

#define LITERAL_BIG_DECIMAL_FULL \
  { LITERAL_DECIMAL_FULL, LITERAL_DECIMAL_FULL }

#define LITERAL_BIG_DECIMAL_MAX \
  { LITERAL_DECIMAL_MAX, LITERAL_DECIMAL_MAX }

#endif  // S21_CONSTANTS_NUM_H_
