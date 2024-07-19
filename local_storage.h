#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef LOCAL_STORAGE_H
#define LOCAL_STORAGE_H

class local_storage
{

private:
    string file_path = "./storage/highest_score.txt";

public:

    local_storage();

    void write_file(string data);
    int read_file();
};


#endif 




