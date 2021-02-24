#include "Word.h"

//Constructors

Word::Word()
{

}

//Destructors

Word::~Word()
{

}

//Getters
string Word::getWord()
{
	return mWord;
}
string Word::getFileLine()
{
	return mLine;
}

//Setters

string Word::setWord(string n)
{
	mWord = n;
	return mWord;
}

string Word::setFileLine(string n)
{
	mLine = n;
	return mLine;
}

