
#include <bits/stdc++.h>
using namespace std;

void mergeInir(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    // low to mid
    // mid + 1 to high

    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeInir(arr, low, mid, high);
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
    mergeSort(arr, 0, n - 1);

    // Output sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



/*
------------using array-----------------

class Solution {
private:
    void merge(vector<int>& nums, int l, int mid, int h) {
        vector<int> temp(h - l + 1);
        int i = l, j = mid + 1, k = 0;
        
        while (i <= mid && j <= h) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= h) temp[k++] = nums[j++];
        
        copy(temp.begin(), temp.end(), nums.begin() + l);
    }
    
    void mergeSort(vector<int>& nums, int l, int h) {
        if (l < h) {
            int mid = l + (h - l) / 2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid + 1, h);
            merge(nums, l, mid, h);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

*/