#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

bool Game_Init(void);
void Game_Shutdown(void);
void Game_Update(void);
void Game_Render(void);
bool Game_Running(void);
void Game_SetMode(int mode);

#define GAME_MODE_CREATIVE 1

#endif

