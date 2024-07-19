#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef PIPE_H
#define PIPE_H

class pipe
{
    private:

    Texture *pipe_texture;
    Sprite *pipe_sprite;

    bool pipe_up = false;

    float init_pos_x = 1920/2;
    float init_pos_y = 1000;

    string path = "./images/";

    public:

    pipe(bool up);
    
    void set_image(bool);
    void init_sprite();
    void init_texture();
    void init_position();
    void set_origin();
    void set_pipe_orientation(bool);
    void set_position(float,float);
    void move_pipe(float);
    void reset_pipe_position(Sprite*,Sprite*,int,int);
    void draw_sprite(RenderWindow*);

    Sprite* return_pipe_sprite();

    FloatRect get_global_bounds();
};
   

#endif 




