/*
paramiterized recursion


#include <bits/stdc++.h>
using namespace std;

void recursionPara(int i, int sum){
    if(i<1){
        cout<< sum;
        return;
    }
    recursionPara(i - 1, sum + i);
}

int main(){
    int n;
    cin>> n;
    recursionPara(5, 0);

}
*/

/*
Functional recursion


#include<bits/stdc++.h>
using namespace std;

int functionalRecSUM(int n){
    if(n == 0){
        return 0;
    }
    return n+ functionalRecSUM(n-1);
}

int main(){
    int n;
    cin>> n;
    cout<< functionalRecSUM(n);

}
*/

/*
reversing an array using using recursion


#include <bits/stdc++.h>
using namespace std;

void revArr(int i, int arr[], int n){
    if(i >= n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    revArr(i+1,arr, n);

}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n; i++){
        cin>> arr[i];
    }
    revArr(0,arr, n);

    for(int i= 0; i< n; i++){
        cout << arr[i];
    }
    return 0;
}
*/

/*
Palindrome number checker

*/

#include <bits/stdc++.h>
using namespace std;

bool palindromeChecker(int i, string &s)
{
   if(i>= s.size()/2){
    return true;
   }
   if(s[i] != s[s.length() - i - 1]){
    return false;
   }
   return palindromeChecker(i+1, s);
    
}

int main()
{
    string s = "madam";
    cout <<palindromeChecker(0, s);
    // return 0;
}