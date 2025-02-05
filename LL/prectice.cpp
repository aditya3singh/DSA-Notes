#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}

    Node(int data, Node *next) : data(data), next(next) {}

    ~Node() { delete next; }

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

Node *getTail(Node *head)
{
    if (!head)
        return NULL;

    while (head->next != NULL)
    {
        head = head->next;

    }
    return head;
}

Node *insertHead(Node *head, int el)
{
    Node *temp = new Node(el, head);
    head = temp;
    return head;
}

Node *insertTail(Node *&tail, int el)
{
    if (tail == nullptr)
    {
        tail = new Node(el);
        return tail;
    }
    Node *temp = new Node(el);
    tail->next = temp;
    tail = temp;
    return tail;
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
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


Node* deleteNode(Node* &head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = converArrtoLL(arr);
    Node *tail = getTail(head);

    int el;
    cout << "Enter the element: ";
    cin >> el;

    printLL(head);
    // head = insertHead(head, el);
    // printLL(head);

    // tail = insertTail(tail, el);
    // printLL(head);

    deleteNode(head);
    printLL(head);

    freeLL(head);
}
