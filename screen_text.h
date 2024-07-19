#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef screen_text_H
#define screen_text_H

class screen_text
{
    private:

    RectangleShape st_background;
    Text st_text;
    Font st_font;
    Color st_bg_color;

    string path = "./fonts/";

    public:

    screen_text(string st_string,Vector2f pos,Color bg_color);

    void init_st_font();
    void init_st_text();
    void init_st_bg_color(Color);
    void set_st_background();
    void set_text_origin();
    void set_text_string(string);
    void set_text_position(Vector2f);
    void set_text_attributes();
    void draw_screen_text(RenderWindow*);
};
   

#endif 




