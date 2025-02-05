#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high; 

    while(i < j){
        while(arr[i] <= pivot && i<= high - 1){
            i++;
        }
        while(arr[j] > pivot && j <= low + 1){
            j--;
        }
        if(i< j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low< high){
        int qIndex = partition(arr, low, high);
        quickSort(arr, low, qIndex - 1);
        quickSort(arr, qIndex + 1, high);

    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    // Input array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call mergeSort
    quickSort(arr, 0, n - 1);

    // Output sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}


/*
class Solution
{
    public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // Apply quicksort only if there are elements to sort
        while (low < high) {
            // Partition the array and get the pivot index
            int qIndex = partition(arr, low, high);

            // Recursively apply quicksort on the smaller part first to optimize recursion depth
            if (qIndex - 1 - low < high - (qIndex + 1)) {
                quickSort(arr, low, qIndex - 1);
                low = qIndex + 1; // Continue sorting the right part
            } else {
                quickSort(arr, qIndex + 1, high);
                high = qIndex - 1; // Continue sorting the left part
            }
        }
    }
    
    public:
    int partition(int arr[], int low, int high)
    {
       // Pivot is chosen as the first element
       int pivot = arr[low];
       int i = low;
       int j = high;

       while (i < j) {
           // Move i to the right until an element greater than the pivot is found
           while (arr[i] <= pivot && i < high) {
               i++;
           }
           // Move j to the left until an element smaller than or equal to the pivot is found
           while (arr[j] > pivot && j > low) {
               j--;
           }
           // Swap elements at i and j if they have crossed
           if (i < j) swap(arr[i], arr[j]);
       }
       // Place the pivot element in its correct position
       swap(arr[low], arr[j]);
       return j;
    }
};

*/