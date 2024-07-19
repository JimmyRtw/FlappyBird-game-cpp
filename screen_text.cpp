#include "screen_text.h"

screen_text :: screen_text(string str,Vector2f pos,Color bg_color)
{
    init_st_font();
    init_st_text();
    init_st_bg_color(bg_color);
    set_text_string(str);
    set_text_attributes();
    set_text_position(pos);
}

void screen_text :: set_st_background()
{
    st_background.setSize(Vector2f(st_text.getGlobalBounds().width, st_text.getGlobalBounds().height));
    st_background.setOrigin(st_background.getSize() / 2.0f);
    st_background.setPosition(st_text.getPosition());
    st_background.setFillColor(this->st_bg_color);
    st_background.setOutlineColor(Color(38, 33, 43));
    st_background.setOutlineThickness(3);
    st_background.setScale(2,2);
}

void screen_text :: init_st_bg_color(Color bg_color)
{
    this->st_bg_color = bg_color;
}

void screen_text :: init_st_font()
{
    this->st_font.loadFromFile(path + "sans.ttf");
}

void screen_text :: init_st_text()
{
    this->st_text.setFont(this->st_font);
}

void screen_text :: set_text_string(string str)
{
    this->st_text.setString(str);
    set_text_origin();
    set_st_background();
}

void screen_text :: set_text_position(Vector2f pos)
{
    st_text.setPosition(pos);
}

void screen_text::set_text_origin()
{
    FloatRect textBounds = this->st_text.getLocalBounds();
    this->st_text.setOrigin(textBounds.left + textBounds.width / 2.0f,textBounds.top + textBounds.height / 2.0f);
}

void screen_text :: set_text_attributes()
{
    set_text_origin();
    this->st_text.setCharacterSize(30);
    this->st_text.setFillColor(Color(0, 0, 0));
}

void screen_text :: draw_screen_text(RenderWindow* window)
{
    window->draw(this->st_background);
    window->draw(this->st_text);
}