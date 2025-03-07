#include "iostream"
#include "fstream"
#include "vector"
#include "sstream"
using namespace std;
void replaceMissingNum(vector<int>& arr){
	int difference = arr[1]-arr[0];
	for(int i = 1; i<arr.size()-1;i++)
		difference = min(difference, arr[i+1] - arr[i]);
	bool flag = false;
	for(int i=0; i<arr.size() - 1 && !flag; i++)
	{
		if(arr[i]+difference!=arr[i+1])
		{
			arr.insert(arr.begin() + i+1, arr[i]+difference);
			flag = !flag;
		}
	}
}
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		cout<<"File name required"<<endl;
		return 1;
	}
	ifstream file(argv[1]);
	if(!file){
		cout<<"File not found!"<<endl;
		return 1;
	}
	vector<int> arr;
	string line;
	int nums[100], cnt = 0;
	while(getline(file, line)){
		stringstream ss(line);
		int num;
		char ch;
		while(ss>>num)
		{
			arr.push_back(num);
			ss>>ch;
		}
	}
	file.close();
	cout<<"Series (read from file) -> ";
	for(int term: arr) cout<<term<<" ";
	replaceMissingNum(arr);
	cout<<"\nMissing term replace -> ";
	for(int term:arr) cout<<term<<" ";
	return 0;
}
