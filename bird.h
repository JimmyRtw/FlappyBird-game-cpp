#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef BIRD_H
#define BIRD_H

class bird
{
    private:

    Texture *bird_texture_1,*bird_texture_2,*bird_texture_3;
    Sprite *bird_sprite;

    float vertical_speed = 0;
    float flap = -10;
    float gravity = 0.5;

    float init_pos_x = 1920/2;
    float init_pos_y = 1080/2.11;

    bool alive = true;

    int animation_delay = 5;
    int animation_counter = 0;

    string path = "./images/";

    public:

    bird();
    
    void set_image();
    void set_vertical_speed(float);
    void init_sprite();
    void init_texture();
    void init_position();
    void set_origin();
    void set_position(float,float);
    void animate_bird();
    void draw_sprite(RenderWindow*);
    void update_bird(Event*,int*,vector<FloatRect>);

    Sprite* get_bird();

    bool is_collided(vector<FloatRect> vec,int *game_on);
};
   

#endif 




