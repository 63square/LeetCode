#include <stdbool.h>
#include <stdint.h>

static const uint64_t mask_24 = ((uint64_t)(1) << 24) - 1;
static const uint64_t mask_32 = ((uint64_t)(1) << 32) - 1;
static const uint64_t mask_57 = ((uint64_t)(1) << 57) - 1;

static const uint32_t base_3 = 10 * ((uint64_t)(1) << 24) / 1000 + 1;
static const uint32_t base_4 = 10 * ((uint64_t)(1) << 24) / 10000 + 1;
static const uint64_t base_5 = 10 * ((uint64_t)(1) << 32) / 100000 + 1;
static const uint64_t base_6 = 10 * ((uint64_t)(1) << 32) / 1000000 + 1;
static const uint64_t base_7 = 10 * ((uint64_t)(1) << 48) / 10000000 + 1;
static const uint64_t base_8 = 10 * ((uint64_t)(1) << 48) / 100000000 + 1;
static const uint64_t base_9 = 10 * ((uint64_t)(1) << 57) / 1000000000 + 1;

bool isPalindrome(int x) {
  if (x < 0)
    return false;

  if (x < 100) {
    if (x < 10)
      return true;

    return x / 10 == x % 10;
  }

  if (x < 1000000) {
    if (x < 10000) {
      if (x < 1000) {
        uint32_t d0 = base_3 * x;
        uint32_t d1 = (d0 & mask_24) * 10;
        uint32_t d2 = (d1 & mask_24) * 10;

        return d0 >> 24 == d2 >> 24;
      }

      uint64_t d0 = base_4 * x;
      uint64_t d1 = (d0 & mask_24) * 10;
      uint64_t d2 = (d1 & mask_24) * 10;
      uint64_t d3 = (d2 & mask_24) * 10;

      return d0 >> 24 == d3 >> 24 && d1 >> 24 == d2 >> 24;
    }

    if (x < 100000) {
      uint64_t d0 = base_5 * x;
      uint64_t d1 = (d0 & mask_32) * 10;
      uint64_t d2 = (d1 & mask_32) * 10;
      uint64_t d3 = (d2 & mask_32) * 10;
      uint64_t d4 = (d3 & mask_32) * 10;

      return d0 >> 32 == d4 >> 32 && d1 >> 32 == d3 >> 32;
    }

    uint64_t d0 = base_6 * x;
    uint64_t d1 = (d0 & mask_32) * 10;
    uint64_t d2 = (d1 & mask_32) * 10;
    uint64_t d3 = (d2 & mask_32) * 10;
    uint64_t d4 = (d3 & mask_32) * 10;
    uint64_t d5 = (d4 & mask_32) * 10;

    return d0 >> 32 == d5 >> 32 && d1 >> 32 == d4 >> 32 && d2 >> 32 == d3 >> 32;
  }

  if (x < 100000000) {
    if (x < 10000000) {
      uint64_t d0 = (base_7 * x) >> 16;
      uint64_t d1 = (d0 & mask_32) * 10;
      uint64_t d2 = (d1 & mask_32) * 10;
      uint64_t d3 = (d2 & mask_32) * 10;
      uint64_t d4 = (d3 & mask_32) * 10;
      uint64_t d5 = (d4 & mask_32) * 10;
      uint64_t d6 = (d5 & mask_32) * 10;

      return d0 >> 32 == d6 >> 32 && d1 >> 32 == d5 >> 32 &&
             d2 >> 32 == d4 >> 32;
    }

    uint64_t d0 = (base_8 * x) >> 16;
    uint64_t d1 = (d0 & mask_32) * 10;
    uint64_t d2 = (d1 & mask_32) * 10;
    uint64_t d3 = (d2 & mask_32) * 10;
    uint64_t d4 = (d3 & mask_32) * 10;
    uint64_t d5 = (d4 & mask_32) * 10;
    uint64_t d6 = (d5 & mask_32) * 10;
    uint64_t d7 = (d6 & mask_32) * 10;

    return d0 >> 32 == d7 >> 32 && d1 >> 32 == d6 >> 32 &&
           d2 >> 32 == d5 >> 32 && d3 >> 32 == d4 >> 32;
  }

  if (x < 1000000000) {
    uint64_t d0 = base_9 * x;
    uint64_t d1 = (d0 & mask_57) * 10;
    uint64_t d2 = (d1 & mask_57) * 10;
    uint64_t d3 = (d2 & mask_57) * 10;
    uint64_t d4 = (d3 & mask_57) * 10;
    uint64_t d5 = (d4 & mask_57) * 10;
    uint64_t d6 = (d5 & mask_57) * 10;
    uint64_t d7 = (d6 & mask_57) * 10;
    uint64_t d8 = (d7 & mask_57) * 10;
    return d0 >> 57 == d8 >> 57 && d1 >> 57 == d7 >> 57 &&
           d2 >> 57 == d6 >> 57 && d3 >> 57 == d5 >> 57;
  }

  uint64_t dd = x / 1000000000;
  uint64_t d0 = base_9 * (x % 1000000000);
  uint64_t d1 = (d0 & mask_57) * 10;
  uint64_t d2 = (d1 & mask_57) * 10;
  uint64_t d3 = (d2 & mask_57) * 10;
  uint64_t d4 = (d3 & mask_57) * 10;
  uint64_t d5 = (d4 & mask_57) * 10;
  uint64_t d6 = (d5 & mask_57) * 10;
  uint64_t d7 = (d6 & mask_57) * 10;
  uint64_t d8 = (d7 & mask_57) * 10;

  return dd == d8 >> 57 && d0 >> 57 == d7 >> 57 && d1 >> 57 == d6 >> 57 &&
         d2 >> 57 == d5 >> 57 && d3 >> 57 == d4 >> 57;
}