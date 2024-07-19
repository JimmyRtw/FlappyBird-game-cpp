#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef GROUND_H
#define GROUND_H

class ground
{
    private:

    Texture *ground_texture;
    Sprite *ground_sprite;

    int speed;

    float init_pos_x = 0;
    float init_pos_y = 1080;

    string path = "./images/";

    public:

    ground();
    
    void set_image();
    void set_speed(float);
    void init_sprite();
    void init_texture();
    void init_position();
    void set_origin();
    void move_ground(float);
    void set_position(float,float);
    void reset_ground_position();
    void draw_sprite(RenderWindow*);
};
   

#endif 




