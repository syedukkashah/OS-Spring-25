#include "iostream"
#include "string"
#include "vector"
using namespace std;
void replaceMissingNum(vector<int>& arr)
{
	int difference = arr[1] - arr[0];
	for(int i=1; i<arr.size()-1; i++)
		difference = min(difference, arr[i+1] - arr[i]);
	bool flag = false;
	for(int i=0; i <  arr.size()-1 && !flag; i++)
	{
		if(arr[i]+difference != arr[i+1])
		{
			arr.insert(arr.begin() + i+1, arr[i]+difference);
			flag = !flag;
		}
	}
}
int main(int argc, char* argv[])
{
	if(argc<3)
	{
		cout<<"More inputs required"<<endl;
		return 1;
	}
	vector<int> arr;
	for(int i = 1; i<argc; i++)
		arr.push_back(stoi(argv[i]));

	cout<<"Series -> ";
		for(int term: arr) cout<<term<<" ";
		replaceMissingNum(arr);
		cout<<"\nMissing term replaced -> ";
		for(int term: arr) cout<<term<<" ";
		return 0;
}
