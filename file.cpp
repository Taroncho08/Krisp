#include <iostream>
#include <fstream>

void writing_in_file(const std::string &file_name, const std::string &str)
{
	std::ofstream file(file_name);

	if (!file.is_open())
	{
		std::perror("File opening error");
		exit(1);
	}

	file << str;

	file.close();
}

void read_from_file(const std::string &file_name)
{
	std::string line;
	std::ifstream file(file_name);

	if (!file.is_open())
	{
		std::perror("File openning error");
		exit(1);
	}

	while (std::getline(file, line))
	{
		std::cout << line << '\n';
	}

	file.close();
}

void remove_second_line(const std::string &file_name)
{
	std::string line;
	std::string str;
	std::ifstream file_for_read(file_name);

	if (!file_for_read.is_open())
	{
		std::perror("File opening error");
		exit(1);
	}

	int i = 0;
	while (std::getline(file_for_read, line))
	{
		if (i % 2 == 0)
		{
			str += line + '\n';
		}

		++i;
	}

	file_for_read.close();

	std::ofstream file_for_write(file_name);

	if (!file_for_write.is_open())
	{
		std::perror("File opening error");
		exit(1);
	}

	std::cout << str;
	file_for_write << str;

	file_for_write.close();
}

void reverse_words_in_lines(const std::string &file_name)
{
	std::string line;
	std::string rev_line;

	std::fstream file_for_read(file_name);

	if (!file_for_read.is_open())
	{
		std::perror("File opening error");
		return;
	}

	int idx = 0;

	while (std::getline(file_for_read, line))
	{
		int j = line.size() - 1;

		while (j > 0)
		{
			while (line[j - 1] != ' ' && j != 0)
			{
				--j;
			}

			for (int i = 0; line[j + i] != ' ' && line[j + i] != '\0'; ++i)
			{
				rev_line += line[j + i];
			}
			rev_line += ' ';
			--j;
		}

		rev_line.erase(rev_line.size() - 1);
		rev_line += '\n';

		if ((int)file_for_read.tellg() == -1)
		{
			file_for_read.clear();
			file_for_read.seekp(idx);
			file_for_read << rev_line;
			return;
		}
		else
		{
			idx = (int)file_for_read.tellg();
			file_for_read.seekp((int)file_for_read.tellg() - line.size() - 1);
			file_for_read << rev_line;
		}

		rev_line = "";
	}

	file_for_read.close();
}

