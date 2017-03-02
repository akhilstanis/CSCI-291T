#include <Inputs.h>

Inputs::Inputs()
{
        Mouse_Translate = false;
        Mouse_Roatate = false;

        // Get the window width and height
        windowWidth  = GetSystemMetrics(SM_CXSCREEN);
        windowHeight = GetSystemMetrics(SM_CYSCREEN);

        // Calculation conversion ratio to translate with accuracy
        conversionRatio = (windowWidth/windowHeight)*100;

}

Inputs::~Inputs()
{
    //dtor
}

void Inputs::KeyPressed(Model *Model)
{
  switch (wParam)
            {
                case VK_LEFT:

                     Model->RotateY += 1.0;
                     // Process the LEFT ARROW key.
                    break;

                case VK_RIGHT:
                     Model->RotateY -= 1.0;
                    // Process the RIGHT ARROW key.
                    break;

                case VK_UP:
                     Model->RotateX -= 1.0;
                    // Process the UP ARROW key.
                    break;

                case VK_DOWN:
                     Model->RotateX += 1.0;
                    // Process the DOWN ARROW key.
                    break;

                case VK_HOME:
                     Model->Zoom -= 1.0;
                    // Process the RIGHT ARROW key.
                    break;

                case VK_END:
                     Model->Zoom += 1.0;
                    // Process the RIGHT ARROW key.
                    break;
            }
}

void Inputs::KeyUp()
{
  switch (wParam)
            {
                default:
                break;
            }
}

void Inputs::MouseEventDown(Model *Model, double x,double y)
{

   switch (wParam)
            {
                case MK_LBUTTON:
                        Mouse_Roatate = true;
                    break;

                case MK_RBUTTON:
                     Mouse_Translate =true;

                    // Translate mouse coordinates to the center of window and divide by conversion ratio.
                    Model->TranslateX = (x - (windowWidth/2)) / conversionRatio;
                    Model->TranslateY = (y - (windowHeight/2)) / conversionRatio;

                    break;
                case MK_MBUTTON:

                    break;

                default:
                    break;
            }
}

 void Inputs::MouseEventUp()
 {
    Mouse_Translate =false;
    Mouse_Roatate =false;
 }

void Inputs::MouseWheel(Model *Model,double Delta)
{
    Model->Zoom += Delta/100;
}

void Inputs::MouseMove(Model *Model,double x,double y)
{
      if(Mouse_Translate)
      {
       Model->TranslateX += (x-prev_Mouse_X)/100;
       Model->TranslateY += (y-prev_Mouse_Y)/100;

       prev_Mouse_X =x;
       prev_Mouse_Y =y;
      }

      if(Mouse_Roatate)
      {
        Model->RotateY += (x-prev_Mouse_X)/3;
        Model->RotateX += (y-prev_Mouse_Y)/3;

        prev_Mouse_X =x;
        prev_Mouse_Y =y;
      }
}

