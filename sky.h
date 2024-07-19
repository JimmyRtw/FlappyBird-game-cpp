#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef SKY_H
#define SKY_H

class sky
{
    private:

    Texture *sky_texture;
    Sprite *sky_sprite;

    float init_pos_x = 1920/2;
    float init_pos_y = 1080/2;

    string path = "./images/";

    public:

    sky();
    
    void set_image();
    void init_sprite();
    void init_texture();
    void set_origin();
    void init_position();
    void set_position(float,float);
    void draw_sprite(RenderWindow*);
};
   

#endif 




