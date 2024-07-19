#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#ifndef BOUNDS_H
#define BOUNDS_H

class bounds
{
    private:
        Sprite* sprite;
        RectangleShape boundsShape;
        Color outlineColor;
        float outlineThickness;

    public:

        bounds(Sprite* sprite, const Color outlineColor, float outlineThickness);

        void update();
        void draw_bounds(RenderWindow* window);

};

#endif 