#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>

// ID de la textura única
extern GLuint textureAtlas;

// Funcions
void Texture_LoadAtlas(const char* path);

// Obtenir coordenades UV d’un bloc dins l’atlas
void Texture_GetCoords(int tileX, int tileY, float* u1, float* v1, float* u2, float* v2);

#endif
