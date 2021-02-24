#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Word
{
private:

	string mWord;
	string mLine;

public:

	//Constructors
	Word();

	//Destructors
	~Word();

	//Getters
	string getWord();
	string getFileLine();

	//Setters

	string setWord(string n);
	string setFileLine(string n);



};

