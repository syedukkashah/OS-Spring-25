#include "iostream"
#include "LineCount.h"
#include "WordCount.h"
#include "LetterCount.h"
using namespace std;
int main(){
	string f = "myFile.txt";
	WordCount wc(f);
	cout<<"Word Count -> "<<wc.countWords()<<endl;
	LetterCount lc(f);
	cout<<"Letter Count -> "<<lc.countLetters()<<endl;
	LineCount line(f);
	cout<<"Line Count -> "<<line.countLines()<<endl;
	return 0;
}
