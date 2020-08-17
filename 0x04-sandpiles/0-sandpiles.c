#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"


/**
 * _print_grid - printsa grid
 * @grid: the grid to print
 * Return: none, void
 *
*/
void _print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sum_piles - sums right pile to left
 * @grid1: left grid
 * @grid2: right grid
 * Return: None, void
*/
void sum_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * checker - checks if a grid is unstable
 * @grid: the grid to check
 *
 * Return: 0 if stable else 1
*/
int checker(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
				return (1);
		}
	}
	return (0);
}
/**
 * stabilizer - stabilizes a sandpile
 * @grid1: first grid
 * @grid2: auxiliary grid
 * Return: no return
*/
void stabilizer(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid2[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (i - 1 >= 0)
					grid2[i - 1][j] += 1;
				if (i + 1 <= 2)
					grid2[i + 1][j] += 1;
				if (j + 1 <= 2)
					grid2[i][j + 1] += 1;
				if (j - 1 >= 0)
					grid2[i][j - 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}

	sum_piles(grid1, grid2);
}

/**
 * sandpiles_sum - function to get the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 * Return: void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_piles(grid1, grid2);
	while (checker(grid1) == 1)
	{
		printf("=\n");
		_print_grid(grid1);
		stabilizer(grid1, grid2);
	}
}
