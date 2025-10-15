#include "texture.h"
#include <stdio.h>

GLuint Texture_Load(const char* filename) {
    SDL_Surface* surface = IMG_Load(filename);
    if (!surface) {
        fprintf(stderr, "❌ Error carregant textura: %s\n", IMG_GetError());
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Convertir superfície SDL a format OpenGL
    GLenum format = (surface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, format,
                 surface->w, surface->h, 0,
                 format, GL_UNSIGNED_BYTE, surface->pixels);

    // Filtrat i repetició
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    SDL_FreeSurface(surface);
    glBindTexture(GL_TEXTURE_2D, 0);

    printf("✅ Textura carregada: %s\n", filename);
    return textureID;
}
