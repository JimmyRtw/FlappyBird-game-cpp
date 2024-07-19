#include "score.h"

score::score()
{
    set_image();
}

void score::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
}

void score::init_texture()
{
    for(int i=0;i<=9;i++)
    {
        score_texture.push_back(new Texture());
    }

    for(int i=0;i<=9;i++)
    {
        score_texture[i]->loadFromFile(path+to_string(i)+".png");
    }
}

void score::init_sprite()
{
    for(int i=0;i<=9;i++)
    {
        score_sprite.push_back(new Sprite());
    }

    for(int i=0;i<=9;i++)
    {
        score_sprite[i]->setScale(1.5,1.5);
        score_sprite[i]->setTexture(*score_texture[i]);
    }
}

void score::set_origin()
{
    for(int i=0;i<=9;i++)
    {
        float x = score_sprite[i]->getTexture()->getSize().x * score_sprite[i]->getScale().x;
        float y = score_sprite[i]->getTexture()->getSize().y * score_sprite[i]->getScale().y;

        score_sprite[i]->setOrigin(x / 2, y / 2);
    }

}

void score::set_position(float x, float y,int index)
{
    score_sprite[index]->setPosition(x, y);
}

void score::draw_score(int game_score,RenderWindow*window)
{
    string score = to_string(game_score/5);
    
    float offset = 30*(score_sprite[0]->getScale().x-0.3f);
    float spacing = 0;
    int length = score.size();

    float factor = length/2.f-0.5f;

    factor = factor<0?0:factor;

    for(char c:score)
    {
        Sprite img_copy = *score_sprite[int(c-'0')];
        img_copy.setPosition(1920/2-factor*offset + spacing,1080/6);
        draw_sprite(window,&img_copy);
        spacing+=offset;
    }
}

void score::draw_sprite(RenderWindow* window,Sprite* sprite)
{
    window->draw(*sprite);
}

