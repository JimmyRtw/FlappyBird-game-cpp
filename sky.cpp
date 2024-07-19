#include "sky.h"

sky::sky()
{
    sky_texture = new Texture();   
    sky_sprite = new Sprite();     
    
    set_image();
}

void sky::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
    init_position();
}

void sky::init_texture()
{
    sky_texture->loadFromFile(path + "sky.png");
}

void sky::init_sprite()
{
    sky_sprite->setTexture(*sky_texture);
}

void sky::set_origin()
{
    float x = sky_sprite->getTexture()->getSize().x * sky_sprite->getScale().x;
    float y = sky_sprite->getTexture()->getSize().y * sky_sprite->getScale().y;

    sky_sprite->setOrigin(x / 2, y / 2);
}

void sky::init_position()
{
    set_position(init_pos_x,init_pos_y);
}

void sky::set_position(float x, float y)
{
    sky_sprite->setPosition(x, y);
}

void sky::draw_sprite(RenderWindow* window)
{
    window->draw(*sky_sprite);
}

