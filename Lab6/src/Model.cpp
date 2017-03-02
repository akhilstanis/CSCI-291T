#include <Model.h>
#include <TextureLoader.h>>

TextureLoader *texTop = new TextureLoader();
TextureLoader *texBottom = new TextureLoader();
TextureLoader *texLeft = new TextureLoader();
TextureLoader *texRight = new TextureLoader();
TextureLoader *texFront = new TextureLoader();
TextureLoader *texBack = new TextureLoader();

Model::Model()
{
   RotateX  = 0.0;
   RotateY  = 0.0;
   RotateZ  = 0.0;
   Zoom     = -8.0;
   // TranslateX = 0.0;
   // TranslateY = 0.0;

   // translate_z =-1.0;


}

Model::~Model()
{
    //dtor
}

void Model::ModelInit() {
    texTop->Binder();
    texTop->BindTexture("images/top.jpg");

    texBottom->Binder();
    texBottom->BindTexture("images/bottom.jpg");

    texLeft->Binder();
    texLeft->BindTexture("images/left.jpg");

    texRight->Binder();
    texRight->BindTexture("images/right.jpg");

    texFront->Binder();
    texFront->BindTexture("images/front.jpg");

    texBack->Binder();
    texBack->BindTexture("images/top.jpg");
}

void Model::DrawModel()
{

    glTranslated(TranslateX,-TranslateY,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);
    glutSolidTeapot(1.5);
}

void Model::DrawSkybox(){
    glPushMatrix();
    glTranslated(0,0,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);

    //glScalef(5.5,5.5,5.5);

    texFront->Binder();
   glBegin(GL_QUADS);
    // Front Face
    glNormal3f(0.f, 0.f, 1.f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Top Left Of The Texture and Quad
    glEnd();
    // Back Face
    texBack->Binder();
    glBegin(GL_QUADS);
    glNormal3f(0.f, 0.f, -1.f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
    glEnd();
    // Top Face
    texTop->Binder();
    glBegin(GL_QUADS);
    glNormal3f(0.f, 1.f, 0.f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glEnd();
    // Bottom Face
    texBottom->Binder();
    glBegin(GL_QUADS);
    glNormal3f(0.f, -1.f, 0.f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glEnd();
    // Right face
    texRight->Binder();
    glBegin(GL_QUADS);
    glNormal3f(1.f, 0.f, 0.f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glEnd();
    // Left Face
    texLeft->Binder();
    glBegin(GL_QUADS);
    glNormal3f(-1.f, 0.f, 0.f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad

    glEnd();

    glPopMatrix();

}
