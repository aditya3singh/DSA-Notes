#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *ptr = NULL;
    ptr = new int;

    if (!ptr)
    {
        cout << "allocation of the memory failed";
    }
    else
    {
        *ptr = 5;
        cout << *ptr << endl;
    }
    ///////////////////////////////////////////////////////////////////////////////
    float *m = new float;
    if (!m)
    {
        cout << "allocation of the memory failed";
    }
    else
    {
        *m = 10;
        cout << *m << endl;
    }

    //////////////////////////////////////////////////////////////////////////////
    int size = 5;
    int *arr = new int[size];
    if (!arr)
    {
        cout << "allocation of the memory failed";
    }

    else
    {
        for (int i = 0; i <= size; i++)
        {
            arr[i] = i + 1;
        }

        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
}