#include "Parallax.h"
#include <GL/gl.h>
#include <TextureLoader.h>

TextureLoader *backgroundTex = new TextureLoader();

Parallax::Parallax()
{
  xmax = 1.0f;
  xmin = 0.0f;
  ymax = 1.0f;
  ymin = 0.0f;
}

Parallax::~Parallax()
{
    //dtor
}

void Parallax::ParaInit()
{
	backgroundTex->Binder();
	backgroundTex->BindTexture("images/tex.jpg");
}


void Parallax::DrawBackground(float width, float height)
{
    glBegin(GL_QUADS);

    glTexCoord2f(xmin, ymax);
    glVertex3f(-1*(width/height), -1, -8.0f);

    glTexCoord2f(xmax, ymax);
    glVertex3f( 1*(width/height), -1, -8.0f);


    glTexCoord2f(xmax, ymin);
    glVertex3f( 1*(width/height),  1, -8.0f);

    glTexCoord2f(xmin, ymin);
    glVertex3f(-1*(width/height),  1, -8.0f);

    glEnd();
}
