
#include <GLScene.h>

GLScene::GLScene()
{
   RotateX  = 0.0;
   RotateY  = 0.0;
   RotateZ  = 0.0;
   Zoom     = -8.0;
}

GLScene::~GLScene()
{
    //dtor
}

GLvoid GLScene::ReSizeGLScene(GLsizei Width, GLsizei Height)		// Resize And Initialize The GL Window
{

GLfloat aspectRatio = (GLfloat)Width / (GLfloat)Height;

    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
    glLoadIdentity();									// Reset The Modelview Matrix
}


GLint GLScene::InitGL()										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	return TRUE;										// Initialization Went OK
}

GLint GLScene::DrawGLScene()							// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslated(0.0,0.0,Zoom);
        glRotated(RotateX,1,0,0);
        glRotated(RotateY,0,1,0);
        glRotated(RotateZ,0,0,1);
        glutSolidTeapot(1.5);
    glPopMatrix();


	return TRUE;										// Keep Going
}

