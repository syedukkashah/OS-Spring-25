#include "iostream"
#include "fstream"
#include "cctype"
#ifndef LETTERCOUNT_H
#define LETTERCOUNT_H
using namespace std;
class LetterCount{
	string fn;
	public:
	LetterCount(const string& filename);
	int countLetters();
};
#endif
