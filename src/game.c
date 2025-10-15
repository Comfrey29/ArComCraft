#include "game.h"
#include <stdio.h>

static bool running = true;
static int mode = 0;

bool Game_Init(void) {
    mode = 0;
    running = true;
    printf("Motor del joc inicialitzat.\n");
    return true;
}

void Game_SetMode(int m) {
    mode = m;
    if (mode == GAME_MODE_CREATIVE)
        printf("Mode Creative+ activat!\n");
}

bool Game_Running(void) {
    return running;
}

void Game_Update(void) {
    // Actualitzar lògica del joc
}

void Game_Render(void) {
    // Renderitzar joc (simplificat)
}

void Game_Shutdown(void) {
    printf("Motor del joc aturat.\n");
    running = false;
}

