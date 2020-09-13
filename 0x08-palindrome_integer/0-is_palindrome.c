#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * reverse - reverses a number through division
 * @n: number to reverse
 * @res:result to be returned
 * @remainder: remainder of the operation
 * @quot: the quotient of the operation
 * Return: reversed number
 */

unsigned long reverse(unsigned long n, unsigned long res,
		      unsigned long remainder, unsigned long quot)
{

	remainder = n % 10;
	res = (res * 10) + remainder;
	quot = quot / 10;
	if (quot == 0)
		return (res);
	else
		return (reverse(quot, res, 0, quot));
}


/**
 * is_palindrome - checks if a number is a palindrome
 *
 * @n: the number to be checked
 *
 * Return: 1 if n is palindrome 0 otherwise
 *
 */

int is_palindrome(unsigned long n)
{
	unsigned long reversed;
	unsigned long res = 0;
	unsigned long remainder = 0;
	unsigned long quot = n;

	reversed = reverse(n, res, remainder, quot);

	return (reversed == n ? 1 : 0);
}
