#include <GL/gl.h>

void DrawCube(float x, float y, float z, float size) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glBegin(GL_QUADS);
    // Front
    glColor3f(0.6f, 0.6f, 0.6f); glVertex3f(0,0,0); glVertex3f(size,0,0); glVertex3f(size,size,0); glVertex3f(0,size,0);
    // Back
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(0,0,-size); glVertex3f(size,0,-size); glVertex3f(size,size,-size); glVertex3f(0,size,-size);
    // Left
    glColor3f(0.7f, 0.7f, 0.7f); glVertex3f(0,0,0); glVertex3f(0,0,-size); glVertex3f(0,size,-size); glVertex3f(0,size,0);
    // Right
    glColor3f(0.4f, 0.4f, 0.4f); glVertex3f(size,0,0); glVertex3f(size,0,-size); glVertex3f(size,size,-size); glVertex3f(size,size,0);
    // Top
    glColor3f(0.8f, 0.8f, 0.8f); glVertex3f(0,size,0); glVertex3f(size,size,0); glVertex3f(size,size,-size); glVertex3f(0,size,-size);
    // Bottom
    glColor3f(0.3f, 0.3f, 0.3f); glVertex3f(0,0,0); glVertex3f(size,0,0); glVertex3f(size,0,-size); glVertex3f(0,0,-size);
    glEnd();
    glPopMatrix();
}
