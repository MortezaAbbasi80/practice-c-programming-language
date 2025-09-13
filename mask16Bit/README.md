# Bit Manipulation in C

This project demonstrates basic **bitwise operations** (`ON`, `OFF`, and `INVERT`) on integers in C.

## Features
- **Turn ON a bit** at a given position.
- **Turn OFF a bit** at a given position.
- **Invert (toggle) a bit** at a given position.
- **Print binary representation** of an unsigned integer.

## Functions
- `onBit(num, n)` → Sets the `n`th bit of `num`.
- `offBit(num, n)` → Clears the `n`th bit of `num`.
- `invertBit(num, n)` → Toggles the `n`th bit of `num`.
- `print_binary(x)` → Prints `x` in binary form (grouped by 4 bits).

## Example
```c
unsigned int x = 2;   // 0010 (binary)
onBit(x, 3);          // Output: 1010 (binary)
