#include "local_storage.h"

local_storage::local_storage()
{

}

void local_storage::write_file(string data)
{
    ofstream file(this->file_path,ios::trunc);

    if (file.is_open())
    {
        file << data << endl;
        file.close();
    }
}

int local_storage::read_file()
{
    ifstream file(this->file_path);
    string data;

    if (file.is_open())
    {
        getline(file, data);
        file.close();
    }

    return stoi(data);
}
