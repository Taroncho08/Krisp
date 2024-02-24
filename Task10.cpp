#include <iostream>
#include <fstream>


int main ()
{
    std::string names = "Name1, Name2, Name3, Name4";
    std::ofstream write_file("file.txt");

    if (!write_file.is_open())
    {
        std::perror("File error");
    }
    
    write_file << names;

    write_file.close();

    std::ifstream read_file("file.txt");

    if (!read_file.is_open())
    {
        std::perror("File error");
    }

    std::string str;

    while (std::getline(read_file, str))
    {
        std::cout << str << std::endl;
    }

    read_file.close();



}