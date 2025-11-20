#ifndef VIEW_H
#define VIEW_H

#include <SDL3/SDL.h>
#include <vector>

const int OFFSET = 100;
const int CELL_SIZE = 20;

void RenderOutsideBox(SDL_Renderer *renderer, int width, int height);
void RenderMazeWalls(SDL_Renderer *renderer, int width, int height, std::vector<bool> mazeWalls);

#endif