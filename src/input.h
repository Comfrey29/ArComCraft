#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct {
    bool forward;
    bool backward;
    bool left;
    bool right;
    bool up;
    bool down;
    int mouseX;
    int mouseY;
    bool quit;
} InputState;

void Input_Init(void);
void Input_Update(InputState* input);
void Input_HandleEvent(InputState* input, SDL_Event* event);

#endif
