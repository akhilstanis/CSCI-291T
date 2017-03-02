#ifndef INPUTS_H
#define INPUTS_H

#include <windows.h>
#include <iostream>
#include <Model.h>

using namespace std;
class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void KeyPressed(Model *);
        void KeyUp();
        void MouseEventDown(Model *,double ,double);
        void MouseEventUp();
        void MouseWheel(Model *,double);
        void MouseMove(Model *,double ,double );

        double prev_Mouse_X;
        double prev_Mouse_Y;
        bool Mouse_Translate;
        bool Mouse_Roatate;

        float windowWidth;
        float windowHeight;
        float conversionRatio;

        WPARAM wParam;
    protected:

    private:
};

#endif // INPUTS_H
