#include "gfx3d.h"
#include <stdio.h>

static SDL_Window* window = NULL;
static SDL_GLContext glContext;

bool GFX3D_Init(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window = SDL_CreateWindow("ArCom Creative+ 3D",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        printf("SDL_GL_CreateContext Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, (float)width / height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return true;
}

void GFX3D_Shutdown(void) {
    SDL_GL_DeleteContext(glContext);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void GFX3D_Clear(void) {
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GFX3D_Present(void) {
    SDL_GL_SwapWindow(window);
}

void GFX3D_SetCamera(float x, float y, float z, float pitch, float yaw) {
    glLoadIdentity();
    glRotatef(pitch, 1, 0, 0);
    glRotatef(yaw, 0, 1, 0);
    glTranslatef(-x, -y, -z);
}
