#include "unionFindModel.h"

int find(int cell, std::vector<int> parents)
{
	if (parents[cell] == cell)
		return cell;
	return find(parents[cell], parents);
}

void unite(int i, int j, std::vector<int> &parents)
{
	int parentI = find(i, parents);
	int parentJ = find(j, parents);

	if (parentI == parentJ)
		return;
	else
		parents[parentI] = parentJ;
}

// NOTE: b must be larger index than a
int findWallByCells(int a, int b, int width, int height)
{
	// Check to ensure the two cells exist.
	if (a < 0 || a >= width * height || b < 0 || b >= width * height)
		return -1;

	// Check to ensure the two cells are actually next to each other.
	if (b - a != 1 && b - a != width)
		return -1;

	// The mazeWalls vector is set up as:
	// Vertical lines, left to right, top to bottom
	// Horizontal lines, left to right, top to bottom
	// If the difference is 1, it's a vertical line. If the difference is width, it's a horizontal line.
	if (b - a == 1)
	{
		// Eliminate the possibility of trying two cells on different rows.
		if (b % width == 0)
			return -1;

		return a - (a / width);
	}
	else if (b - a == width)
	{
		// Since horizontal walls come after vertical walls, the first horizontal wall is at index (width - 1) * height.
		return a + (width - 1) * height;
	}
}

std::pair<int, int> findCellsByWall(int w, int width, int height)
{
	std::pair<int,int> cellPair;

	// The mazeWalls vector is set up as:
	// Vertical lines, left to right, top to bottom
	// Horizontal lines, left to right, top to bottom
	// If the wall index is at least (width - 1) * height, it's a horizontal line. Otherwise, it's a vertical line.
	if (w >= (width - 1) * height)
	{
		// Inverse of formula for findWallByCells. Then we know b = a + width since it's a horizontal wall.
		cellPair.first = -((width - 1) * height - w);
		cellPair.second = cellPair.first + width;
	}
	else
	{
		// Inverse of formula for findWallByCells. Then we know b = a + 1 since it's a vertical wall.
		cellPair.first = int(w / float(1 - 1 / width));
		cellPair.second = cellPair.first + 1;
	}

	return cellPair;
}