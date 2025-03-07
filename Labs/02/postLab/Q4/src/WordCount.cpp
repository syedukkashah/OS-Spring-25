#include "WordCount.h"
#include "iostream"
using namespace std;
WordCount::WordCount(const string& filename):fn(filename){}
int WordCount::countWords(){
	ifstream file(fn);
	if(!file)
	{
		cerr<<"Error opening file"<<endl;
		return 1;
	}
	string word;
	int wordCnt = 0;
	while(file>>word)
		wordCnt++;
	file.close();
	return wordCnt;
}

