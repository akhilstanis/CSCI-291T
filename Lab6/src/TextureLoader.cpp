#include "TextureLoader.h"


TextureLoader::TextureLoader()
{
    //ctor
}

TextureLoader::~TextureLoader()
{
    //dtor
}

void TextureLoader::BindTexture()
{

    glGenTextures(1, &tex);
    glEnable(GL_TEXTURE_2D);

    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, tex);  // images are 2D arrays of pixels, bound to the GL_TEXTURE_2D target.

    image = SOIL_load_image("images/1.jpg", &width, &height, 0, SOIL_LOAD_RGB);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);    // binding image data     SOIL_free_image_data(image);

    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void TextureLoader::Binder()
{
    glBindTexture(GL_TEXTURE_2D, tex);
}
