#include "iostream"
#include "fstream"
#include "string"
using namespace std;
class LineCount{
	string fn;
	public:
		LineCount(const string& filename);
		int countLines();
};
