#ifndef GFX_H
#define GFX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

// Inicialització i tancament
bool GFX_Init(int width, int height);
void GFX_Shutdown(void);

// Dibuixar
void GFX_Clear(void);
void GFX_Present(void);

// Carregar textures
SDL_Texture* GFX_LoadTexture(const char* path);

// Renderer accessible des d'altres fitxers
extern SDL_Renderer* renderer;

#endif

