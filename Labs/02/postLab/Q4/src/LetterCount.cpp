#include "LetterCount.h"
using namespace std;
LetterCount::LetterCount(const string& filename):fn(filename){}
int LetterCount:: countLetters(){
	ifstream file(fn);
	if(!file)
	{
		cerr<<"Error opening file "<<endl;
		return 1;
	}
	string word;
	int wordCnt = 0;
	while(file >> word)
		wordCnt++;
	
	file.close();
	return wordCnt;
}

