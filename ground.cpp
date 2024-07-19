#include "ground.h"

ground::ground()
{
    ground_texture = new Texture();   
    ground_sprite = new Sprite();     
    
    set_image();
}

void ground::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
    init_position();
}

void ground::set_speed(float speed)
{
    this->speed = speed;
}

void ground::init_texture()
{
    ground_texture->loadFromFile(path + "ground.png");
}

void ground::init_sprite()
{
    ground_sprite->setTexture(*ground_texture);
}

void ground::init_position()
{
    set_position(init_pos_x,init_pos_y);
}

void ground::set_origin()
{
    float x = ground_sprite->getTexture()->getSize().x * ground_sprite->getScale().x;
    float y = ground_sprite->getTexture()->getSize().y * ground_sprite->getScale().y;

    ground_sprite->setOrigin(0, y);
}

void ground::set_position(float x, float y)
{
    ground_sprite->setPosition(x, y);
}

void ground::draw_sprite(RenderWindow* window)
{
    window->draw(*ground_sprite);
}

void ground::move_ground(float speed)
{
    set_speed(speed);

    float pos_x = ground_sprite->getPosition().x;
    float pos_y = ground_sprite->getPosition().y;

    ground_sprite->setPosition(pos_x-this->speed,pos_y);
    
    reset_ground_position();
}

void ground::reset_ground_position()
{
    float pos_x = ground_sprite->getPosition().x;
    float pos_y = ground_sprite->getPosition().y;

    if(pos_x<=-1920)
    {
        set_position(0,1080);
    }
}