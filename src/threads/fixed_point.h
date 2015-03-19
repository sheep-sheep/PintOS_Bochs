#ifndef __FIXED_POINT_H
#define __FIXED_POINT_H

/* Basic definitions of fixed point. */

/* The following table summarizes how fixed-point arithmetic operations can be implemented in C. In the table, x and y are fixed-point numbers, n is an integer, fixed-point numbers are in signed p.q format where p  q = 31, and f is 1 << q:
Convert n to fixed point:	n * f
Convert x to integer (rounding toward zero):	x / f
Convert x to integer (rounding to nearest):	(x + f / 2) / f if x >= 0, 
(x - f / 2) / f if x <= 0.
Add x and y:	x + y
Subtract y from x:	x - y
Add x and n:	x + n * f
Subtract n from x:	x - n * f
Multiply x by y:	((int64_t) x) * y / f
Multiply x by n:	x * n
Divide x by y:	((int64_t) x) * f / y
Divide x by n:	x / n
*/
typedef int fixed_t;
#define FP_F (1 << 14)

/* Convert n to fixed point:	n * f */
#define FP_CONST(N) ((fixed_t)(N * FP_F)
/* Add x and y:	x + y */
#define FP_ADD(X,Y) (X + Y)
/* Add x and n:	x + n * f */
#define FP_ADD_MIX(X,N) (X + (N * FP_F))
/* Subtract y from x:	x - y*/
#define FP_SUB(X,Y) (X - Y)
/* Subtract n from x:	x - n * f */
#define FP_SUB_MIX(X,N) (X - (N * FP_F))
/* Multiply x by n:	x * n. */
#define FP_MULT_MIX(X,N) (X * N)
/* Divide x by n:	x / n */
#define FP_DIV_MIX(X,N) (X / N)
/* Multiply x by y:	((int64_t) x) * y / f */
#define FP_MULT(X,Y) ((fixed_t)(((int64_t) X) * Y / FP_F))
/* Divide x by y:	((int64_t) x) * f / y */
#define FP_DIV(X,Y) ((fixed_t)(((int64_t) X) * FP_F / Y))
/* Convert x to integer (rounding toward zero):	x / f */
#define FP_INT_PART(X) (X / FP_F)
/* Convert x to integer (rounding to nearest) */
#define FP_ROUND(X) (X >= 0 ? ((X + FP_F / 2) / FP_F) : ((X - FP_F / 2) / FP_F))

#endif
