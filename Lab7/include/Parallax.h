#ifndef PARALLAX_H
#define PARALLAX_H


class Parallax
{
    public:
        Parallax();
        virtual ~Parallax();
        void DrawBackground(float width, float height);
        float xmax, xmin, ymax, ymin;
        void ParaInit();

    protected:

    private:
};

#endif // PARALLAX_H
