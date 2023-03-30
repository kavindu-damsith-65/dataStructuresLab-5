#include <iostream>
#include <stack>
#include <chrono>
using namespace std;

void quicksort(int arr[], int n)
{
  stack<int> stack;
  int l = 0, r = n - 1;
  stack.push(l);
  stack.push(r);

  while (!stack.empty())
  {
    r = stack.top();
    stack.pop();
    l = stack.top();
    stack.pop();

    int i = l, j = r;
    int pivot = arr[(l + r) / 2];

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

    if (l < j)
    {
      stack.push(l);
      stack.push(j);
    }
    if (i < r)
    {
      stack.push(i);
      stack.push(r);
    }
  }
}

int main()
{
  srand(time(NULL));                                                      // seed the random number generator
  int arr1[] = {10, 100, 400, 1000, 2000, 3000, 4000, 6000, 8000, 10000}; // length of the array

  for (int k = 0; k < 10; k++)
  {
    int n = arr1[k];
    int arr[n];

    // fill the array with random integers
    for (int i = 0; i < n; i++)
    {
      arr[i] = rand() % 10000;
    }

    // measure the running time of quicksort
    auto start = chrono::high_resolution_clock::now();
    quicksort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    cout << "Length of array:"<<arr1[k]<<"   Elapsed time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
  }
  return 0;
}
