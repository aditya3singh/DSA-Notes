#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream file("fileDemo.txt", ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "error to open the file";
    }
    else
    {
        cout << file.tellp() << endl;
        // file << "he is you good";
        string line;
        getline(file, line);
        // cout << line<<endl;
        cout << file.tellp() << endl;

        file.seekp(20);

        file << "kup is now where";

        cout << endl;

        // cout << file.tellp();
    }
}