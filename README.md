# Questions

## What's `stdint.h`?

A Microsoft's library of using different types of integers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The ability to use BYTE, DWORD, LONG and WOR respectively.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE is an 8-bit unsigned value = 1 byte
A DWORD is a 32-bit unsigned integer = 4 bytes
A LONG is a 32-bit signed integer = 4 bytes
A WORD is a 16-bit unsigned integer = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM (in ACCII)

## What's the difference between `bfSize` and `biSize`?

biSize is the number of bytes required by the structure.
bfSize is the size, in bytes, of the bitmap file.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If there's not enough memory or a file doesn't exist.

## Why is the third argument to `fread` always `1` in our code?

for 1 struct

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

It allows to rewind within a file.

## What is `SEEK_CUR`?

current position in file

## Whodunit?

Professor Plum
