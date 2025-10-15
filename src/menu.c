#include "menu.h"
#include "game.h"
#include <stdio.h>

static void Menu_CreativePlus(void) {
    printf("Entrant al mode Creative+...\n");
    Game_SetMode(GAME_MODE_CREATIVE);
}

void Menu_Show(void) {
    int choice = 0;

    while (choice != 3) {
        printf("\n=== ArCom Corporation ===\n");
        printf("1. Creative+ Mode\n");
        printf("2. Exit\n");
        printf("------------------------\n");
        printf("Tria una opcio: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Menu_CreativePlus();
                break;
            case 2:
                choice = 3;
                break;
            default:
                printf("Opcio invalida.\n");
                break;
        }
    }
}

