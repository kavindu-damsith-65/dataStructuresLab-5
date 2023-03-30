#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

vector<int> findMedian(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    double median;
    if (arr.size() == 1)
    {
        median = static_cast<double>(arr[0]);
    }
    else if (arr.size() % 2 == 1)
    {
        median = static_cast<double>(arr[arr.size() / 2]);
    }
    else
    {
        median = (static_cast<double>(arr[arr.size() / 2]) + static_cast<double>(arr[arr.size() / 2 - 1])) / 2;
    }

    cout<<"[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if(i!=arr.size()-1){
             cout<<" ,";
        }
    }
    cout<<" ]    ";

    cout << fixed << setprecision(1) << median << endl;

    return arr;
}

int main()
{
    // Create an empty vector of integers
    vector<int> arr;

    srand(time(NULL)); // seed the random number generator
    int n;             // length of the array
    cout << "Enter the length of array: ";

    while (true)
    {
        cin >> n;
        if (cin.fail() || n<1){

            cout << "Error: Invalid input, please enter a positive integer: ";
            cin.clear();                                         // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining characters in the input buffer
        }
        else{
            break;
        }
    }
    // vector<int> arr1 = {7, 3, 5, 2};
    // int n = 4;
    for (int i = 0; i < n; i++)
    {
        arr.push_back( rand() % 100);
        arr = findMedian(arr);
    }

    return 0;
}
