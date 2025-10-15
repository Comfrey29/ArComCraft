#include "input.h"

void Input_Init(void) {
    SDL_SetRelativeMouseMode(SDL_TRUE); // Captura el ratolí dins la finestra
}

void Input_Update(InputState* input) {
    // Reiniciar moviment per frame
    input->forward = input->backward = false;
    input->left = input->right = false;
    input->up = input->down = false;

    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    input->forward  = keystate[SDL_SCANCODE_W];
    input->backward = keystate[SDL_SCANCODE_S];
    input->left     = keystate[SDL_SCANCODE_A];
    input->right    = keystate[SDL_SCANCODE_D];
    input->up       = keystate[SDL_SCANCODE_SPACE];
    input->down     = keystate[SDL_SCANCODE_LSHIFT];
}

void Input_HandleEvent(InputState* input, SDL_Event* event) {
    switch (event->type) {
        case SDL_MOUSEMOTION:
            input->mouseX = event->motion.xrel;
            input->mouseY = event->motion.yrel;
            break;

        case SDL_QUIT:
            input->quit = true;
            break;

        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_ESCAPE)
                input->quit = true;
            break;
    }
}
