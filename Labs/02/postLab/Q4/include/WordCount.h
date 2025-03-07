#ifndef WORDCOUNT_H
#define WORDCOUNT_H
#include "iostream"
#include "fstream"
#include "string"
using namespace std;
class WordCount{
	string fn;
	public:
	WordCount(const string& filename);
	int countWords();
};
#endif
