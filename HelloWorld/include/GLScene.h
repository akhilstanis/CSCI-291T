#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h> // Header File For Windows
#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

using namespace std;
class GLScene
{

    public:
        GLScene();
        virtual ~GLScene();
        GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
        GLint InitGL();
        GLint DrawGLScene();

        double RotateX;
        double RotateY;
        double RotateZ;
        double Zoom;

    protected:

    private:

};

#endif // GLSCENE_H
