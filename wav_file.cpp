#include <iostream>
#include <fstream>

void print_wav_file(const std::string& file_name)
{
    std::ifstream file(file_name);
    std::string line;

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
}

void copy_wav_file (const std::string& file_name)
{
    std::ifstream read_file(file_name);
    std::ofstream write_file(file_name + "_copy.wav");
    std::string line;

    while (std::getline(read_file, line))
    {
        write_file << line + "\n";
    }

    read_file.close();
    write_file.close();
}

