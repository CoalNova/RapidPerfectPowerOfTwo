# RapidPerfectPowerOfTwo
An entirely **unstable, unreliable, and dangerous** method of calculating if a provided. No license is provided, as this method should never be used.

During a back and forth conversation regarding finding the fastest method of finding a perfect power of two, several solutions were discussed. At settling on counting the individual bits of a provided integer, an individual chimed in that a much worse version could be used. Through checking the mantissa of an IEEE 754 floating point number, and bitwise checking it against 0x00 then the number is a perfect power of two. For those familiar with how single-precision floats operate, this obviously has an upper limit of 4194304, cares nothing for the concept of negative, and does not account for a majority of edge cases.
