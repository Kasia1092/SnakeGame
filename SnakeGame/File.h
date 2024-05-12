#pragma once

#include <memory>
#include <vector>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ranges>
#include <algorithm>


class File 
{
public:
	File();
	~File();

	void fileIn();
	void fileOut();
	void bestScores();
	void addScore(int score);

	std::vector<std::string> vec;

private:
	std::string path = "board.txt";

	std::stringstream ss;
	std::string data;

};