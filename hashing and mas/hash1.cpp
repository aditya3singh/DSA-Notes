/*
---This is normal array and number cheacking problem

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n; i++){
        cin>> arr[i];
    }

    //precompute
    int hash[13] = {0};
    for(int i= 0; i< n; i++){
        hash[arr[i]] += 1;
    }


    int q;
    cout <<"q ";
    cin>>q;
    while(q--){
        int number;
        cin>> number; 

        cout<< hash[number] << endl; 
    }
    return 0;
}

*/

/*
---This is the String conversion proplem for checking that the problem 


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"String name: ";
    cin>> s;

    int hash[256] = {0};
    for(int i= 0; i< s.size(); i++){
        hash[s[i]]++;
    } 
    int q;
    cin>> q;
    while(q--){
        char c;
        cout<< "c: ";
        cin>> c;
        cout<< hash[c]<<endl;;//fetching the data
    }
    return 0;
}
*/


/*
Number of elements presents in the map present in order as we take inputs 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n; i++){
        cin >> arr[n];
    }

    //pre-compute
    map<int, int> mpp;
    for(int i= 0; i< n; i++){
        mpp[arr[i]]++;
    }

    int q;
    cin>> q;
    while(q--){
        int number;
        cin>> number;
        //fetch
        cout << mpp[number]<<endl;;
    }

    return 0;
}