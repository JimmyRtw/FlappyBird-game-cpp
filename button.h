#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

#ifndef BUTTON_H
#define BUTTON_H

class button {

private:

    RectangleShape* button_shape;
    Text* button_text;
    Font button_font;
    string button_string;
    
    bool is_clicked;
    bool is_hovered;

    string path = "./fonts/";

public:

    button(string text,float,float);

    void init_button_font();
    void set_button_size();
    void set_button_origin();
    void set_button_pos(float,float);
    void set_button_color();
    void set_button_border();
    void set_button_text();
    void set_text_origin();
    void set_events(Event*,int*);
    void set_hover_events();
    void set_click_events(int*);
    void draw_button(RenderWindow*);
    void init_button();

    bool is_button_clicked();

};

#endif