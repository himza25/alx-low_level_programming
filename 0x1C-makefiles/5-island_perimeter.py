#!/usr/bin/python3
"""
Module for calculating the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    The grid is a list of list of integers where 0 represents water and
    1 represents land. Cells are connected horizontally/vertically.
    """
    width = len(grid[0])
    height = len(grid)
    perimeter = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i-1][j] == 1:  # Check the cell above
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:  # Check the cell to the left
                    perimeter -= 2
    return perimeter
