# fsqrt
Based on Chris Lomont's [paper](https://www.lomont.org/Math/Papers/2003/InvSqrt.pdf) on the [fast inverse square root](https://en.wikipedia.org/wiki/Fast_inverse_square_root) C routine found in the source code from Quake III Arena i've implmented a square root c routine based on the method there described to derive the magic constant for an initial approximation and Newton-Raphson iterations for improvement of that value.

#TODO:
* Time testing on ARMv7 architecture
* Detailed tests against math.h sqrt
* Tests against SSE2 sqrt instructions
* Improve intial approximation
* Use uint32_t instead of unsigned
* Derive for double
* Compare with f * invsqrt(f)
