

#include <bits/stdc++.h>
using namespace std;

/*
The Largest elements
int largestElement(int arr[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largestElement(arr, n);
}
*/


/*
secondLargest 

5
5
6
8
3
9
9

#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n)
{
    int max = arr[0];
    int smax = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];

        }
        else if(arr[i] < max && arr[i] > smax){
            smax = arr[i];
        }
    }
    return smax;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largestElement(arr, n);
}
*/


/*
Second Smallest


#include <bits/stdc++.h>
using namespace std;

int secondSmallestElement(int arr[], int n)
{
    int min = arr[0];
    int smin = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            smin = min;
            min = arr[i];

        }
        else if(arr[i] > min && arr[i] < smin){
            smin = arr[i];
        }
    }
    return smin;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << secondSmallestElement(arr, n);
}
*/
/*
smallest Element



#include <bits/stdc++.h>
using namespace std;

int smallestElement(int arr[], int n){
    int min = INT_MAX;
    for(int i= 0; i< n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int n;
    cin>> n;

    int arr[n];
    for(int i= 0; i< n; i++){
        cin >> arr[i];
    }

    cout << smallestElement(arr, n);
}
*/

/*
Sorted Checker

*/

int sortedChecker(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin>> n;

    int arr[n];
    for(int i= 0; i< n; i++){
        cin >> arr[i];
    }

    cout << sortedChecker(arr, n);
}