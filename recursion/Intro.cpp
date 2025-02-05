/*this is the normal print from 1 to n


#include <iostream>
#include <string>
using namespace std;

void recursion(int i, int n, const string& name) {
    if (i > n) {
        return;
    }
    // cout<< i<<endl;
    
    cout <<i<<", "<<name << endl;
    recursion(i + 1, n, name);
}

int main() {
    int n;
    string name;
    
    cout << "Enter a name: ";
    cin >> name;
 
    cout << "Enter the number of times to print: ";
    cin >> n;

    recursion(1, n, name);
    
    return 0;
}
*/

/*
this will print from 1 to n using the backtracking


#include <iostream>
#include <string>
using namespace std;

void recursion(int i, int n, const string& name) {
    if (i < 1) {
        return;
    }
    // cout<< i<<endl;
    
    recursion(i - 1, n, name);
    cout <<i<<", "<<name << endl;
}

int main() {
    int n;
    string name;
    
    cout << "Enter a name: ";
    cin >> name;
    
    cout << "Enter the number of times to print: ";
    cin >> n;

    recursion(n, n, name);
    
    return 0;
}
*/

/*
print from n to 1 using normal technique

*/

#include <bits/stdc++.h>
using namespace std;

void recursion(int i, int n, string name){
    if(i>n){
        return;
    }
    recursion(i + 1, n, name);
    cout <<i<<", "<<name << endl;
}

int main() {
    int n;
    string name;
    
    cout << "Enter a name: ";
    cin >> name;
    
    cout << "Enter the number of times to print: ";
    cin >> n;

    recursion(1, n, name);
    
    return 0;
}