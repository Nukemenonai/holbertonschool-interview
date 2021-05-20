#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
/**
 * _isnumber - checks if string is number
 *
 * @s: string
 *
 * Return: 1 if string is number, else 0
 */
int _isnumber(char *str)
{
	int i, val, d;

	d = 0, val = 1;
	for (i = 0; *(str + i) != 0; i++)
	{
		d = isdigit(*(str + i));
		if (d == 0)
		{
			val = 0;
			break;
    	}
	}
	return (val);
}

/**
 * _callocX - reserves memory initialized to 0
 *
 * @nmemb: # of bytes
 *
 * Return: pointer
 */
char *_callocX(unsigned int nmemb)
{
	unsigned int i;
	char *p;

	p = malloc(nmemb + 1);
	if (p == 0)
		return (0);
	for (i = 0; i < nmemb; i++)
		p[i] = '0';
	p[i] = '\0';
	return (p);
}

/**
 * main - multiplies inf numbers
 *
 * @argc: n. of cmd line args
 * @argv: line args
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i, j, len1, len2, sum, mul, add, t1, t2, tl, zer = 0;
	char *res;

	if (argc != 3 || _isnumber(argv[1]) == 0 || _isnumber(argv[2]) == 0)
		printf("Error\n"), exit(98);
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
		printf("0\n"), exit(0);
	len1 = strlen(argv[1]), len2 = strlen(argv[2]);
	sum = len1 + len2;
	res = _callocX(sum);
	if (res == 0)
		printf("Error\n"), exit(98);
	for (i = len2 - 1; i >= 0; i--)
	{
		t1 = 0, t2 = 0;
		for (j = len1 - 1; j >= 0; j--)
		{
			tl = i + j + 1;
			mul = (argv[1][j] - '0') * (argv[2][i] - '0') + t1;
			t1 = mul / 10;
			add = (res[tl] - '0') + (mul % 10) + t2;
			t2 = add / 10;
			res[tl] = (add % 10) + '0';
		}
		res[tl - 1] = (t1 + t2) + '0';
	}
	if (res[0] == '0')
		zer = 1;
	for (; zer < sum; zer++)
		printf("%c", res[zer]);
	printf("\n");
	free(res);
	return (0);
}
