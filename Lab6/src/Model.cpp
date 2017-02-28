#include <Model.h>
#include <TextureLoader.h>>

TextureLoader *tex = new TextureLoader();

Model::Model()
{
   RotateX  = 0.0;
   RotateY  = 0.0;
   RotateZ  = 0.0;
   Zoom     = -8.0;
   TranslateX = 0.0;
   TranslateY = 0.0;
}

Model::~Model()
{
    //dtor
}

void Model::ModelInit() {
    tex->Binder();
    tex->BindTexture();
}

void Model::DrawModel()
{

    glTranslated(TranslateX,-TranslateY,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);
    glutSolidTeapot(1.5);
}
