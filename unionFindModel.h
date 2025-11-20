#ifndef MODEL_H
#define MODEL_H

#include <SDL3/SDL.h>
#include <vector>

int find(int cell, std::vector<int> parents);
void unite(int i, int j, std::vector<int> &parents);
int findWallByCells(int a, int b, int width, int height);
std::pair<int, int> findCellsByWall(int w, int width, int height);

#endif