#include "texture.h"
#include <stdio.h>

GLuint textureAtlas;
int atlasSize = 256;  // mida total de la imatge atlas
int tileSize  = 16;   // mida de cada bloc dins l’atlas

// Carrega només l’atlas complet
void Texture_LoadAtlas(const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        fprintf(stderr, "❌ Error carregant textura atlas: %s\n", IMG_GetError());
        textureAtlas = 0;
        return;
    }

    glGenTextures(1, &textureAtlas);
    glBindTexture(GL_TEXTURE_2D, textureAtlas);

    GLenum format = (surface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, format,
                 surface->w, surface->h, 0,
                 format, GL_UNSIGNED_BYTE, surface->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    SDL_FreeSurface(surface);
    glBindTexture(GL_TEXTURE_2D, 0);

    printf("✅ Atlas carregat: %s\n", path);
}

// Retorna coordenades UV per un bloc dins l’atlas
void Texture_GetCoords(int tileX, int tileY, float* u1, float* v1, float* u2, float* v2) {
    float ts = (float)tileSize / atlasSize;
    *u1 = tileX * ts;
    *v1 = tileY * ts;
    *u2 = *u1 + ts;
    *v2 = *v1 + ts;
}

