#include "iostream"
#include "string"
#include "vector"
using namespace std;
void insertionSort(vector<int>& array){
	for(int i=1; i<array.size(); i++){
		int key = array[i];
		int j = i-1;
		while (j>=0 && array[j]>key){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}
int main(int argc, char* argv[])
{
	if(argc < 3){
		cout<<"More arguments required"<<endl;
		return 0;
	}
	vector <int> arr;
	for(int i=1; i<argc; i++)
		arr.push_back(stoi(argv[i]));

	insertionSort(arr);
	for(int num: arr) cout<<num<<" ";
	return 0;
}
		
