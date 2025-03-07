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
	char ch;
	int letterCnt = 0;
	while(file.get(ch)){
		if(isalpha(ch))
			letterCnt++;
	}
	file.close();
	return letterCnt;
}

