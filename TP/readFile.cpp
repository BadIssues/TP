#include <string>
#include <fstream>
#include <vector>
#include "readFile.h"

std::vector<std::vector<std::string>> readFile()
{
	std::string _line;
	std::vector<std::string> line;

	std::ifstream file;
	file.open("cmd.txt"); //cmd.txt doit contenir les commandes permettant de g�n�rer des formes selon ses param�tres

	while (std::getline(file, _line)) //S�pare le txt en lignes
	{
		line.push_back(_line);
	}

	std::string word;
	std::vector<std::string> sentence;
	std::vector<std::vector<std::string>> text;

	for (int row = 0; row < line.size(); row++) //Parcours chaque ligne
	{
		for (int column = 0; column < line[row].size(); column++) //Parcours chaque caract�re
		{
			if (line[row][column] != ' ')
			{
				word += line[row][column];
			}
			else
			{
				sentence.push_back(word);
				word.clear();
			}
		}
		sentence.push_back(word);
		word.clear();
		text.push_back(sentence);
		sentence.clear();
	}

	return text;
}