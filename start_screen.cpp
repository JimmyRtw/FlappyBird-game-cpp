#include "start_screen.h"

start_screen::start_screen()
{
    start_screen_texture = new Texture();   
    start_screen_sprite = new Sprite();     
    
    set_image();
}

void start_screen::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
    init_position();
}

void start_screen::init_texture()
{
    start_screen_texture->loadFromFile(path + "start_screen.png");
}

void start_screen::init_sprite()
{
    start_screen_sprite->setTexture(*start_screen_texture);
}

void start_screen::set_origin()
{
    float x = start_screen_sprite->getTexture()->getSize().x * start_screen_sprite->getScale().x;
    float y = start_screen_sprite->getTexture()->getSize().y * start_screen_sprite->getScale().y;

    start_screen_sprite->setOrigin(x/2, y/2);
}

void start_screen::set_position(float x, float y)
{
    start_screen_sprite->setPosition(x, y);
}

void start_screen::init_position()
{
    set_position(init_pos_x,init_pos_y);
}

void start_screen::draw_sprite(RenderWindow* window)
{
    window->draw(*start_screen_sprite);
}

