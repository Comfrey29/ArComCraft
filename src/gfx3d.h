#ifndef GFX3D_H
#define GFX3D_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdbool.h>

bool GFX3D_Init(int width, int height);
void GFX3D_Shutdown(void);
void GFX3D_Clear(void);
void GFX3D_Present(void);
void GFX3D_SetCamera(float x, float y, float z, float pitch, float yaw);

#endif
