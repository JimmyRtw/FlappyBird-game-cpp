#include "pipe.h"

pipe::pipe(bool up)
{
    pipe_texture = new Texture();   
    pipe_sprite = new Sprite();     
    
    set_image(up);
}

void pipe::set_image(bool up)
{
    set_pipe_orientation(up);
    init_texture();
    init_sprite();
    set_origin();
    init_position();
}

void pipe::set_pipe_orientation(bool up)
{
    this->pipe_up = up;
}

void pipe::init_texture()
{
    string mid = pipe_up==true?"_up":"_down";

    pipe_texture->loadFromFile(path + "pipe" + mid + ".png");
}

void pipe::init_sprite()
{
    pipe_sprite->setTexture(*pipe_texture);
}

void pipe::set_origin()
{
    float x = pipe_sprite->getTexture()->getSize().x * pipe_sprite->getScale().x;
    float y = pipe_sprite->getTexture()->getSize().y * pipe_sprite->getScale().y;

    y = pipe_up==true?0:y;

    pipe_sprite->setOrigin(x / 2, y);
}

void pipe::set_position(float x, float y)
{
    pipe_sprite->setPosition(x, y);
}

void pipe::draw_sprite(RenderWindow* window)
{
    window->draw(*this->pipe_sprite);
}

void pipe :: move_pipe(float speed)
{
    pipe_sprite->setPosition(pipe_sprite->getPosition().x - speed, pipe_sprite->getPosition().y);
}

void pipe :: reset_pipe_position(Sprite* side_img,Sprite* top_img,int hor_dist,int ver_dist)
{
    int range = 150 + (rand() % (int)(590 - 150 + 1));

    float x = pipe_sprite->getTexture()->getSize().x * pipe_sprite->getScale().x; 

    float position = this->pipe_sprite->getPosition().x + x/2;

    float side_img_pos_x = side_img->getPosition().x;
    float side_img_pos_y = top_img==NULL? range : top_img->getPosition().y+ver_dist;

    if(position<0)
    {
        this->pipe_sprite->setPosition(side_img_pos_x+hor_dist,side_img_pos_y);
    }
}

void pipe :: init_position()
{
    set_position(init_pos_x,init_pos_y);
}

Sprite* pipe :: return_pipe_sprite()
{
    return this->pipe_sprite;
}

FloatRect pipe :: get_global_bounds()
{
    return this->pipe_sprite->getGlobalBounds();
}
