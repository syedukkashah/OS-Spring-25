#include "iostream"
#include "fstream"
using namespace std;
int main(int argc, char* argv[]){
	if(argc<2){
		cerr<<"Usage: "<<argv[0]<<" <filename>\n";
		return 1;
	}
	ifstream file(argv[1]);
	if(!file){
		cerr<<"File can't be opened!"<<endl;
		return 1;
	}
	string line;
	while(getline(file, line)){
		cout<<line<<endl;
	}
	file.close();
	return 0;
}
