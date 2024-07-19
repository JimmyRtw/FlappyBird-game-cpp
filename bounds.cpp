#include "bounds.h"

bounds :: bounds(Sprite* sprite, const Color outlineColor, float outlineThickness)
{
    this->sprite = sprite;
    this->outlineColor = outlineColor;
    this->outlineThickness = outlineThickness;

    boundsShape.setFillColor(Color::Red);
    boundsShape.setOutlineColor(outlineColor);
    boundsShape.setOutlineThickness(outlineThickness);
}

void bounds :: update()
{
    FloatRect bounds = sprite->getGlobalBounds();
    boundsShape.setSize(Vector2f(bounds.width, bounds.height));
    boundsShape.setPosition(bounds.left, bounds.top);
}

void bounds :: draw_bounds(RenderWindow* window)
{
    window->draw(boundsShape);
}