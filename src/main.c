#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "game.h"

int main(void) {
    printf("ArCom Creative+ Edition\n");

    // Inicialitzar motor gràfic i joc
    if (!Game_Init()) {
        printf("Error inicialitzant el joc.\n");
        return 1;
    }

    // Mostrar menú principal
    Menu_Show();

    // Bucle principal
    while (Game_Running()) {
        Game_Update();
        Game_Render();
    }

    Game_Shutdown();
    return 0;
}

