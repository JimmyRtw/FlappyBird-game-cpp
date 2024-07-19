#include "button.h"

button::button(string text, float x, float y)
{
    this->button_string = text;

    init_button();
    init_button_font();
    set_button_size();
    set_button_origin();
    set_button_pos(x, y);
    set_button_color();
    set_button_border();
    set_button_text();
}

void button::init_button()
{
    button_shape = new RectangleShape();
    button_text = new Text();
}

void button::init_button_font()
{
    this->button_font.loadFromFile(path + "sans.ttf");
}

void button::set_button_size()
{
    this->button_shape->setSize(Vector2f(200, 50));
}

void button::set_button_origin()
{
    Vector2f size = button_shape->getSize();
    button_shape->setOrigin(size.x / 2.f, size.y / 2.f);
}

void button::set_button_pos(float x, float y)
{
    this->button_shape->setPosition(x, y);
}

void button::set_button_color()
{
    button_shape->setFillColor(Color(47, 192, 245));
}

void button::set_button_border()
{
    button_shape->setOutlineColor(Color(38, 33, 43));
    button_shape->setOutlineThickness(5);
}

void button::set_text_origin()
{
    FloatRect textBounds = button_text->getLocalBounds();
    button_text->setOrigin(textBounds.left + textBounds.width / 2.0f,textBounds.top + textBounds.height / 2.0f);
}

void button::set_button_text()
{
    set_text_origin();
    
    button_text->setString(button_string);
    button_text->setFont(button_font);
    button_text->setCharacterSize(30);
    button_text->setFillColor(Color(0, 0, 0));

    FloatRect textBounds = button_text->getLocalBounds();
    Vector2f position = button_shape->getPosition();
    Vector2f size = button_shape->getSize();
    button_text->setPosition(position.x - textBounds.width / 2.f, position.y - textBounds.height / 1.2f);
}

void button::set_events(Event* event,int* game_on)
{
    if (event->type == Event::MouseButtonPressed && event->mouseButton.button == Mouse::Left)
    {
        if (button_shape->getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
        {
            this->is_clicked = true;

            set_click_events(game_on);
        }
    }
    else if (event->type == Event::MouseButtonReleased && event->mouseButton.button == Mouse::Left)
    {
        this->is_clicked = false;
    }
    else if (event->type == Event::MouseMoved)
    {
        if (button_shape->getGlobalBounds().contains(event->mouseMove.x, event->mouseMove.y))
        {
            is_hovered = true;

            set_hover_events();
        }
        else
        {
            is_hovered = false;

            set_hover_events();
        }
    }
}

void button::set_hover_events()
{
    if(this->is_hovered)
    {
        button_shape->setFillColor(Color(7, 71, 92));
        button_text->setFillColor(Color(255, 255, 255));
        button_shape->setOutlineColor(Color(255, 255, 255));
    }
    else
    {
        button_shape->setFillColor(Color(47, 192, 245));
        button_text->setFillColor(Color(0, 0, 0));
        button_shape->setOutlineColor(Color(38, 33, 43));
    }
}

void button::set_click_events(int* game_on)
{
    if(this->is_clicked and *game_on==2)
    {
        this->is_clicked = false;

        if(this->button_string=="Restart")
        {
            *game_on = 3;
        }
        else if(this->button_string=="Quit")
        {
            exit(0);
        }
    }
}

void button::draw_button(RenderWindow* window)
{
    window->draw(*button_shape);
    window->draw(*button_text);
}

bool button::is_button_clicked()
{
    return this->is_clicked;
}
