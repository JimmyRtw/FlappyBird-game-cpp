#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef START_SCREEN_H
#define START_SCREEN_H

class start_screen
{
    private:

    Texture *start_screen_texture;
    Sprite *start_screen_sprite;

    int speed;

    float init_pos_x = 1920/2;
    float init_pos_y = 1080/2.7;

    string path = "./images/";

    public:

    start_screen();
    
    void set_image();
    void init_sprite();
    void init_texture();
    void set_origin();
    void set_position(float,float);
    void init_position();
    void draw_sprite(RenderWindow*);
};
   

#endif 




