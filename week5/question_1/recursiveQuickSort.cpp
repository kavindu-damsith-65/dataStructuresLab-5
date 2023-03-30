#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void quicksort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main()
{
    srand(time(NULL)); // seed the random number generator
    int arr1[]={10,100,400,1000,2000,3000,4000,6000,8000,10000};             // length of the array
    
    
   

    for(int k=0;k<10;k++){
        int n=arr1[k];
        int arr[n];

        // fill the array with random integers
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 1000000;
        }

        // cout << "Sorting " << n << " elements..." << endl;

        // measure the running time of quicksort
        auto start = chrono::high_resolution_clock::now();
        quicksort(arr, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();

        cout << "Length of array:"<<arr1[k]<<"   Elapsed time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
    }
    return 0;
}
