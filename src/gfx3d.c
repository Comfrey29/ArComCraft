#include "gfx3d.h"
#include <GL/glu.h>

void Gfx_Init(int width, int height) {
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, (float)width/height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Gfx_DrawCube(float x, float y, float z, GLuint texture,
                  float u1, float v1, float u2, float v2) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_QUADS);
    // Front
    glTexCoord2f(u1, v2); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(u2, v2); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(u2, v1); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(u1, v1); glVertex3f(-0.5, 0.5, 0.5);
    // Back
    glTexCoord2f(u1, v2); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(u2, v2); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(u2, v1); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(u1, v1); glVertex3f(-0.5, 0.5, -0.5);
    // Other sides...
    glEnd();

    glPopMatrix();
}
