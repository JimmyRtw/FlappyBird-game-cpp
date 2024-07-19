#include "pipe_manager.h"

pipe_manager :: pipe_manager()
{
    set_tnop(9);
    set_indexes();
    set_ver_dist(220);
    set_hor_dist(450);
    init_pipes();
    init_pipes_origin();
    init_pipes_position();
}

void pipe_manager :: set_tnop(int n)
{
    this->n = n;
}

void pipe_manager :: set_indexes()
{
    this->first_index = 0;
    this->last_index = n-1;
}

void pipe_manager :: set_speed(float speed)
{
    this->speed = speed;
}

void pipe_manager :: set_ver_dist(int ver_dist)
{
    this->ver_dist = ver_dist;
}

void pipe_manager :: set_hor_dist(int hor_dist)
{
    this->hor_dist = hor_dist;
}

void pipe_manager :: init_pipes()
{
    for (int i = 0; i < this->n; i++)
    {
        up_pipes.push_back(new pipe(true));
        down_pipes.push_back(new pipe(false));
    }
}

void pipe_manager :: draw_pipes(RenderWindow* window)
{
    for(int i=0;i<this->n;i++)
    {
        pipe* up_pipe = up_pipes[i];
        pipe* down_pipe = down_pipes[i];

        up_pipe->draw_sprite(window);
        down_pipe->draw_sprite(window);
    }
}

void pipe_manager :: init_pipes_position()
{
    this->first_index = 0;
    this->last_index = n-1;

    float x = 1920/1.1;
    float y = 150 + (rand() % (int)(590 - 150 + 1));

    for(int i=0;i<this->n;i++)
    {
        pipe* up_pipe = up_pipes[i];
        pipe* down_pipe = down_pipes[i];

        up_pipe->set_position(x,y+ver_dist);
        down_pipe->set_position(x,y);

        x += hor_dist;
        y = 150 + (rand() % (int)(590 - 150 + 1));
    }
}

void pipe_manager :: init_pipes_origin()
{
    for(int i=0;i<this->n;i++)
    {
        pipe* up_pipe = up_pipes[i];
        pipe* down_pipe = down_pipes[i];

        up_pipe->set_origin();
        down_pipe->set_origin();   
    }
}

void pipe_manager :: move_pipes(float speed)
{
    set_speed(speed);

    for(int i=0;i<this->n;i++)
    {
        pipe* up_pipe = up_pipes[i];
        pipe* down_pipe = down_pipes[i];

        up_pipe->move_pipe(this->speed);
        down_pipe->move_pipe(this->speed);   
    }

    pipe_reset_position();
}

void pipe_manager :: pipe_reset_position()
{
    pipe* up_pipe = up_pipes[first_index];
    pipe* down_pipe = down_pipes[first_index];

    down_pipe->reset_pipe_position(down_pipes[last_index]->return_pipe_sprite(),nullptr,hor_dist,ver_dist);
    up_pipe->reset_pipe_position(up_pipes[last_index]->return_pipe_sprite(),down_pipe->return_pipe_sprite(),hor_dist,ver_dist);
    
    last_index = first_index;
    first_index = (first_index+1)%n;
}

void pipe_manager :: set_game_score(int* game_score)
{
    for(int i=0;i<this->n;i++)
    {
        pipe* cross_pipe = up_pipes[i];

        float x = cross_pipe->return_pipe_sprite()->getTexture()->getSize().x * cross_pipe->return_pipe_sprite()->getScale().x; 
        float position = cross_pipe->return_pipe_sprite()->getPosition().x + x/2;

        if(position<=(1920/2) and position>=(1920/2-15))
        {
            *game_score += 1;
            break;
        }
    }

}

vector<FloatRect> pipe_manager :: pipes_global_bounds()
{
    vector<FloatRect>vec;

    for(int i=0;i<n;i++)
    {
        vec.push_back(up_pipes[i]->get_global_bounds());
        vec.push_back(down_pipes[i]->get_global_bounds());
    }

    return vec;
}
