/*
//this is the basic code for the LL


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

int main(){
    vector <int> arr = {2,5,6,7,8};
    Node* y = new Node(arr[0]);
    cout << y;
}
*/

/*
//this is for the conversion of array to LL


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};
Node* converArrtoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i= 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next  = temp;
        mover = temp;
    }
    return head;
}


int main(){
    vector <int> arr = {2,5,6,7,8};
    Node* head = converArrtoLL(arr);
    cout << head -> data;
}
*/

/*
//this is for the treversal of the LL


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};
Node* converArrtoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i= 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next  = temp;
        mover = temp;
    }
    return head;
}



int main(){
    vector <int> arr = {2,5,6,7,8};
    Node* head = converArrtoLL(arr);
    Node* temp = head;

    while(temp){
    cout << temp -> data<< " ";
    temp = temp->next;

    }

}
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};
Node* converArrtoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i= 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next  = temp;
        mover = temp;
    }
    return head;
}



int main(){
    vector <int> arr = {2,5,6,7,8};
    Node* head = converArrtoLL(arr);
    Node* temp = head;

    while(temp){
    cout << temp -> data<< " ";
    temp = temp->next;

    }

}
*/

/*

//This is for the length of the linked list

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
Node *converArrtoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// length of the LL
int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
int checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    vector<int> arr = {2, 5, 6, 7, 8};
    Node *head = converArrtoLL(arr);
    Node *temp = head;
    cout << checkIfPresent(head, 5);
    // while(temp){
    // cout << temp -> data<< " ";
    // temp = temp->next;
    // }
}
