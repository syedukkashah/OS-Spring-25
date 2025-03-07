#include "LineCount.h"
using namespace std;
LineCount::LineCount(const string& filename):fn(filename){}
int LineCount::countLines(){
	ifstream file(fn);
	if(!file){
		cerr<<"Error opening file"<<endl;
		return 1;
	}
	string line;
	int lineCnt = 0;
	while(getline(file, line))
		lineCnt++;
	file.close();
	return lineCnt;
}
