#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to check if the input is a valid integer
bool isValidInteger(const string& str, int& num) {
    try {
        num = stoi(str);  // Try converting string to integer
        return true;  // If successful, return true
    } catch (const invalid_argument& e) {
        return false;  // If conversion fails, return false
    } catch (const out_of_range& e) {
        return false;  // If the number is out of range
    }
}

// Function to calculate the sum of the array
int sum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// Function to calculate the average of the array
double average(const vector<int>& arr) {
    if (arr.size() == 0) return 0;  // Avoid division by zero
    return static_cast<double>(sum(arr)) / arr.size();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {  // Error if the number of integers in CLI arguments < 2
        cerr << "Usage: " << argv[0] << " <integer1> <integer2> ...\n";
        return 1;
    }

    vector<int> arr;  // Declare the array once before the loop

    for (int i = 1; i < argc; i++) {
        int num;
        if (!isValidInteger(argv[i], num)) {
            cerr << "Error: invalid int input " << argv[i] << " ..\n";
            return 1;
        }
        arr.push_back(num);  // Add the valid integer to the vector
    }

    sort(arr.begin(), arr.end());  // Sort the vector

    cout << "Sorted Array -> ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Sum: " << sum(arr) << endl;
    cout << "Average: " << average(arr) << endl;

    return 0;
}

