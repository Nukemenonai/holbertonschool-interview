#!/usr/bin/python3
""" ISLAND PERIMETER """


def island_perimeter(grid):
    """returns the perimeter of an island in a grid"""
    perimeter = 0
    m = len(grid)
    n = len(grid[0])
    for i in range(m):
        for j in range(n):
            if grid[i][j]:
                if not j or not grid[i][j-1]:
                    perimeter += 1
                if not i or not grid[i-1][j]:
                    perimeter += 1
                if j == n - 1 or not grid[i][j+1]:
                    perimeter += 1
                if i == m - 1 or not grid[i+1][j]:
                    perimeter += 1
    return perimeter
