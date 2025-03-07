#include "iostream"
#include "LineCount.h"
#include "WordCount.h"
#include "LetterCount.h"
using namespace std;
int main(){
	string f = "myFile.txt";
	WordCount wc(f);
	cout<<wc.countWords()<<endl;
	LetterCount lc(f);
	cout<<lc.countLetters()<<endl;
	LineCount line(f);
	cout<<line.countLines()<<endl;
	return 0;
}
