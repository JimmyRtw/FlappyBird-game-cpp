#include "bird.h"

bird::bird()
{
    bird_texture_1 = new Texture();   
    bird_texture_2 = new Texture();   
    bird_texture_3 = new Texture();   

    bird_sprite = new Sprite();     
    
    set_image();
}

void bird::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
    init_position();
}

void bird::init_position()
{
    set_position(init_pos_x,init_pos_y);
}

void bird::set_vertical_speed(float vertical_speed)
{
    this->vertical_speed = vertical_speed;
}

void bird::init_texture()
{
    bird_texture_1->loadFromFile(path + "bird_1.png");
    bird_texture_2->loadFromFile(path + "bird_2.png");
    bird_texture_3->loadFromFile(path + "bird_3.png");
}

void bird::init_sprite()
{
    bird_sprite->setTexture(*bird_texture_1);
}

void bird::set_origin()
{
    float x = bird_sprite->getTexture()->getSize().x * bird_sprite->getScale().x;
    float y = bird_sprite->getTexture()->getSize().y * bird_sprite->getScale().y;

    bird_sprite->setOrigin(x/2, y/2);
}

void bird::set_position(float x, float y)
{
    bird_sprite->setPosition(x, y);
}

void bird::animate_bird()
{
    animation_counter++;

    if (animation_counter == animation_delay)
    {
        bird_sprite->setTexture(*bird_texture_2);
    }
    else if (animation_counter == (animation_delay * 2))
    {
        bird_sprite->setTexture(*bird_texture_3);
    }
    else if (animation_counter == (animation_delay * 3))
    {
        bird_sprite->setTexture(*bird_texture_1);
        animation_counter = 0;
    }  
}


void bird::update_bird(Event* event,int* game_on,vector<FloatRect> vec)
{
    if(is_collided(vec,game_on)) return;

    this->vertical_speed += this->gravity;

    if(this->vertical_speed>=-10 and (event->type == Event::MouseButtonPressed or event->type == Event::KeyPressed or Keyboard::isKeyPressed(Keyboard::Key::Space) or Keyboard::isKeyPressed(Keyboard::Key::Up)))
    {
        this->vertical_speed = this->flap;
    }

    float pos = bird_sprite->getPosition().y + this->vertical_speed;

    set_position(1920/2,pos);
    animate_bird();
}

bool bird::is_collided(vector<FloatRect> vec,int *game_on)
{
    // check for the collision with the pipes

    FloatRect bird_bounds = bird_sprite->getGlobalBounds();

    for(FloatRect pipe_bounds:vec)
    {
        if(bird_bounds.intersects(pipe_bounds))
        {
            *game_on = 2;

            this->alive = false;

            return true;;
        }
    }

    // check for the collision with the top and bottom of the screen

    float pos_offset = (bird_sprite->getTexture()->getSize().y * bird_sprite->getScale().y)/2;
    float curr_pos = bird_sprite->getPosition().y;

    if((curr_pos+pos_offset)>=(1080-184) or (curr_pos-pos_offset)<=0)
    {
        this->alive = false;

        *game_on = 2;

        return true;
    }

    return false;
}

Sprite* bird :: get_bird()
{
    return this->bird_sprite;
}

void bird::draw_sprite(RenderWindow* window)
{
    window->draw(*bird_sprite);
}
