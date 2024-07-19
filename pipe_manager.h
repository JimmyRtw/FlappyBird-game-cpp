#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

#include "pipe.h"

using namespace std;
using namespace sf;

#ifndef PIPE_MANAGER_H
#define PIPE_MANAGER_H

class pipe_manager
{
    private:

    int n;

    vector<pipe*>up_pipes;
    vector<pipe*>down_pipes;

    int ver_dist;
    int hor_dist;
    float speed = 0.2;

    int first_index;
    int last_index;

    public:

    pipe_manager();

    void set_tnop(int);
    void set_indexes();
    void set_speed(float);
    void set_ver_dist(int);
    void set_hor_dist(int);
    void set_game_score(int *game_score);
    void init_pipes();

    void draw_pipes(RenderWindow* window);
    void init_pipes_position();
    void init_pipes_origin();
    void move_pipes(float);
    void pipe_reset_position();

    vector<FloatRect> pipes_global_bounds();
};
   
#endif





