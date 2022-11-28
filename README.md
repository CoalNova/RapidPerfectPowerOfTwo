# RapidPowerOfTwo
An entirely **unstable, unreliable, and dangerous** method of calculating if a provided number is a power of two(2). No license is provided, as this method should never be used. This exists as a demonstration.

During a back and forth conversation regarding finding the fastest method of finding a power of two, several solutions were discussed. At settling on counting the individual bits of a provided integer, an individual chimed in that a much worse version could be used. Through checking the mantissa of an IEEE 754 floating point number, and bitwise masking it for 0x00, the passing number is a power of two. For those familiar with how single or double-precision floats operate this obviously has ridiculous limits, cares nothing for the concept of negative, and does not account for a majority of edge or even normal cases.

Compiling using -O2 or higher on clang, gcc/g++, and msvc produces this code:
```as
cvtsi2ss %esi,%xmm0
movd     %xmm0,%eax
test     $0x7fffff,%eax
```
And operating off of the result.
