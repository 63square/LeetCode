# Intuition
My first thought was to simply floor divide $$x$$ by 10 in a loop, extracting all the digits and comparing them similar to a naive `itoa` function. This appears to be the most common solution for this problem.

# Approach
The issue with my initial idea is that it's quite inefficient for larger numbers and all inputs are processed the same regardless of magnitude. An improvement is unrolling the loop to process more likely inputs faster which is what I did for the Python version.

But floor division and modulo aren't very fast operations when used on large numbers, instead we can use a combination of shifting and multiplication to achieve better performance. Unfortunately this does not work with Python due to the overhead of the `int` type.

To extract the `3` from `321` we would need to do something like `321 / 100` but this division can be quite slow. In most scenarios it is faster to use multiplication and shifting, to do this we need to create a multiplier using binary tricks.

By precomputing `m = (1 << N) / d` where $$d$$ is the divisor, and then computing `(x * m) >> N`, we approximate `x / d` efficiently.

We can do this for a 32 bit number with the following code, notice that an extra `10 *` is added, this is needed for enough accuracy to perform the operations correctly:
```c
uint64_t m = 10 * (1 << 32) / (d * 10);
```

For `/ 100` like the previous example this becomes:
```c
uint64_t m = 10 * (1 << 32) / 1000;
```

We can perform the operation on a number by multiplying it by the result and then shifting it
```c
uint64_t d0 = 321 * m;

d0 >> 32 // 3
```

The interesting part about this method is you can continue to extract digits by applying a mask and multiplying by 10, for example:
```c
uint64_t multiplier = 10 * (1 << 32) / 1000;
uint64_t mask = (1 << 32) - 1;

uint64_t d0 = 321 * multiplier;
uint64_t d1 = (d0 & mask) * 10;
uint64_t d2 = (d1 & mask) * 10;

d0 >> 32 // 3
d1 >> 32 // 2
d2 >> 32 // 1
```

Repeating this allows you to efficiently extract and compare digits, while this problem isn't the most practical this method can be applied in more important algorithms such as integer to string conversion.

# Complexity
- Time complexity:
$$O(1)$$

- Space complexity:
$$O(1)$$
