#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gfx3d.h"
#include "input.h"
#include "texture.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("ArComCraft 3D",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext ctx = SDL_GL_CreateContext(window);

    Gfx_Init(800, 600);
    Input_Init();

    Texture_LoadAtlas("assets/textures/texture.png");

    InputState input = {0};
    float camX = 0, camY = 1.5, camZ = 5;

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) Input_HandleEvent(&input, &e);
        Input_Update(&input);
        if (input.quit) running = false;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(camX, camY, camZ, 0,0,0, 0,1,0);

        float u1,v1,u2,v2;
        Texture_GetCoords(0,0,&u1,&v1,&u2,&v2); // grass
        Gfx_DrawCube(0,0,0,textureAtlas,u1,v1,u2,v2);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
