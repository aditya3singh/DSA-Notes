#include <iostream>
using namespace std;

void stringNumber(string nameStr){
    int number = nameStr.length();
    cout <<"the length of the string is :- " <<number;
}

int main(){
    string name;
    cin>> name;

    stringNumber(name);
}





