#include "gfx.h"
#include <stdio.h>

static SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool GFX_Init(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("ArCom Creative+", 
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

void GFX_Shutdown(void) {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void GFX_Clear(void) {
    // Color de fons gris fosc
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);
}

void GFX_Present(void) {
    SDL_RenderPresent(renderer);
}

SDL_Texture* GFX_LoadTexture(const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        printf("IMG_Load Error: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!tex) {
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        return NULL;
    }

    return tex;
}

