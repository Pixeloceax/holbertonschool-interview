#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome.
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{

	unsigned long reversed = 0;
	unsigned long original = n;

	while (n != 0)
	{
		reversed = reversed * 10;
		reversed = reversed + n % 10;
		n = n / 10;
	}

	if (original == reversed)
		return (1);
	else
		return (0);
}
