#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;

#ifndef SCORE_H
#define SCORE_H

class score
{
    private:

    vector<Texture*>score_texture;
    vector<Sprite*>score_sprite;

    string path = "./images/";

    public:

    score();
    
    void set_image();
    void init_sprite();
    void init_texture();
    void set_origin();
    void set_position(float,float,int);
    void draw_score(int,RenderWindow*);
    void draw_sprite(RenderWindow*,Sprite*);
};
   

#endif 




