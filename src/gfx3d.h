#ifndef GFX3D_H
#define GFX3D_H

#include <GL/gl.h>

// Inicialitza OpenGL
void Gfx_Init(int width, int height);

// Dibuixa un cub amb textura (atlas)
void Gfx_DrawCube(float x, float y, float z, GLuint texture,
                  float u1, float v1, float u2, float v2);

#endif
