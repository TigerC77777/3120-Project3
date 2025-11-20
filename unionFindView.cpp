#include "unionFindView.h"

void RenderOutsideBox(SDL_Renderer *renderer, int width, int height)
{
    SDL_RenderLine(renderer, OFFSET, OFFSET, OFFSET + width * CELL_SIZE, OFFSET);
    SDL_RenderLine(renderer, OFFSET + width * CELL_SIZE, OFFSET, OFFSET + width * CELL_SIZE, OFFSET + (height - 1) * CELL_SIZE);
    SDL_RenderLine(renderer, OFFSET, OFFSET + CELL_SIZE, OFFSET, OFFSET + height * CELL_SIZE);
    SDL_RenderLine(renderer, OFFSET, OFFSET + height * CELL_SIZE, OFFSET + width * CELL_SIZE, OFFSET + height * CELL_SIZE);
}

void RenderMazeWalls(SDL_Renderer *renderer, int width, int height, std::vector<bool> mazeWalls)
{
    for (int i = 0; i < mazeWalls.size(); i++)
    {
        if (mazeWalls[i])
        {
            // Horizontal walls
            if (i >= (width - 1) * height)
            {
                int xPos = OFFSET + ((i - (width - 1) * height) % width) * CELL_SIZE;
                int yPos = OFFSET + (((i - (width - 1) * height) / width) + 1) * CELL_SIZE;
                SDL_RenderLine(renderer, xPos, yPos, xPos + CELL_SIZE, yPos);
            }
            // Vertical walls
            else
            {
                int xPos = OFFSET + (i % (width - 1) + 1) * CELL_SIZE;
                int yPos = OFFSET + (i / (width - 1)) * CELL_SIZE;
                SDL_RenderLine(renderer, xPos, yPos, xPos, yPos + CELL_SIZE);
            }
        }
    }
}