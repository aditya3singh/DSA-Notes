/*
Write a C++ program to create and display a Singly Linked List.
Test Data:
The list contains the data entered:
11 9 7 5 3 1

*/
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
/*
Node* deleteHead(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    head = head-> next;
    free(temp);
    return head;

}
*/
/*
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp ->next->next != NULL){
        temp = temp ->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;

}
*/
/*
Node* removeKth(Node* head, int k){
    if(head == NULL) return NULL;
    if(k == 1){
        Node* temp = head;
        head = head ->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp= head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
*/
/*
Node* removeKth(Node* head, int el){
    if(head == NULL) return NULL;
    if(head->data == el){
        Node* temp = head;
        head = head ->next;
        free(temp);
        return head;
    }
    Node* temp= head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {11, 9, 7, 5, 3, 1};
    Node *head = converArrtoLL(arr);
    // head = deleteHead(head);
    // head = removeTail(head);
    // head = removeKth(head, 3);
    int el;
    cin>>el;
    head = removeKth(head, el);
    print(head);
}
*/

// Insertion sort in  LL

/*


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Add a constructor that takes both data and next pointer
    Node(int data, Node* next) : data(data), next(next) {}
};

Node *converArrtoLL(vector<int> &arr)
{
    if (arr.empty()) return NULL;

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

void print(Node *head)
{
    cout << "The list contains: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertHead(Node* head, int val) {
    return new Node(val, head);
}

Node* insertTail(Node* head, int val){
    if(head == NULL) return new Node(val);

    Node*temp = head;
    while(temp ->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp ->next = newNode;
    return head;
}

Node* insertToPosition(Node* head, int el, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k == 1){
        return new Node(el, head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == ( k - 1)){
            Node* x = new Node(el, temp ->next);
            temp ->next = x;
            break;
        }
        temp = temp->next
    }
    return head;
}

int main()
{
    vector<int> arr = {11, 9, 7, 5, 3, 1};
    Node *head = converArrtoLL(arr);

    cout << "Original list:" << endl;
    print(head);

    cout << "Enter a value to insert at the head: ";
    int el;
    cin >> el;

    head = insertTail(head, el);

    cout << "List after insertion:" << endl;
    print(head);
    cout << "Enter a value to insert at the head: ";
    int el;
    cin >> el;

    head = insertTail(head, el);

    cout << "List after insertion:" << endl;
    print(head);

    // Clean up the memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Add a constructor that takes both data and next pointer
    Node(int data, Node* next) : data(data), next(next) {}
};

Node *converArrtoLL(vector<int> &arr)
{
    if (arr.empty()) return NULL;

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

Node* insertElement (Node* head, int el){
    return new Node(el, head);
}

void printEl(Node* head){
    cout<< "the LinkedList is to be like this: ";
    while(head!= NULL){
        cout<< head -> data<<" ";
        head = head ->next;
    }
    cout << endl;
}



int main()
{
    vector<int> arr = {11, 9, 7, 5, 3, 1};
    Node *head = converArrtoLL(arr);
    int el;
    cin>> el;
    head = insertElement(head, el);

    printEl(head);


}
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}

    Node(int data, Node *next) : data(data), next(next) {}
};

Node *converArrtoLL(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

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

void insertAtPosition(Node *&head, int el, int position)
{
    if (position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1)
    {
        head = new Node(el, head);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1 )
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == nullptr)
    {
        cout << "Position exceeds the length of the list" << endl;
        return;
    }

    Node *newNode = new Node(el);
    newNode->next = temp->next;
    temp->next = newNode;
}

Node *getTail(Node *head)
{
    if (!head)
        return nullptr;
    while (head->next != nullptr)
        head = head->next;
    return head;
}

Node *insertHead(Node *&head, int el)
{
    Node *newNode = new Node(el, head);
    head = newNode;
    return head;
}

Node *insertTail(Node *&tail, int el)
{
    if (tail == nullptr)
    {
        tail = new Node(el);
        return tail;
    }
    Node *newNode = new Node(el);
    tail->next = newNode;
    tail = newNode;
    return tail;
}

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void freeLL(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = converArrtoLL(arr);
    Node *tail = getTail(head); // Initialize tail to the last node of the list
    cout << "Original LL" << endl;
    printLL(head);

    cout << "Enter the value of the element to insert at head and tail: ";
    int el, position;
    cin >> el;
    // head = insertHead(head, el);
    // cout << "LL after inserting at head:" << endl;
    // printLL(head);

    // tail = insertTail(tail, el);
    // cout << "LL after inserting at tail:" << endl;
    // printLL(head);

    cout << "Enter the position: ";
    cin >> position;
    cout << "Inserting to any position: " << endl;
    insertAtPosition(head, el, position);
    printLL(head);

    freeLL(head);

    return 0;
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) left++;
                else if (sum > 0) right--;
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
};
