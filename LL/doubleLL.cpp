#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

Node *converArrToLL(vector<int> &arr)
{

    if (arr.empty())
        return NULL;
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

Node *insertHeadLL(Node *&head, int el)
{
    Node *newNode = new Node(el);
    // newNode->data = el;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node *insertBtwLL(Node *&head, int el, int pos)
{
    if (pos == 0)
        return insertHeadLL(head, el);
    Node *newNode = new Node(el);
    Node *mover = head;
    int i = 0;
    while (mover != NULL && i < pos - 1)
    {
        mover = mover->next;
        i++;
    }
    if (mover == NULL)
        return head;
    newNode->next = mover->next;
    mover->next = newNode;
    return head;
}

Node *deleteDLLHead(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
    return head;
}

Node *deleteAfterLL(Node *&head, int key)
{
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == key)
        {
            if (curr->next == NULL)
            {
                return head;
            }

            Node *deleteNode = curr->next;

            curr->next = deleteNode->next;

            if (deleteNode->next != NULL)
                deleteNode->next->prev = curr;
            delete deleteNode;
            return head;
        }
        curr = curr->next;
    }
    return head;
}

void reverse(Node* &head)
{
    if (head == NULL || head->next == NULL) return;

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    head = prev;
}




Node *deletebeforeLL(Node *&head, int key)
{
    if (head == NULL)
        return head;

    if (head->data == key)
    {
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->next->data == key)
        {
            Node *deleteNode = curr->next;
            curr->next = deleteNode->next;

            if (deleteNode->next != NULL)
                deleteNode->next->prev = curr;
            delete deleteNode;
            return head;
        }
        curr = curr->next;
    }
    return head;
}

Node *deleteAtPos(Node *&head, int pos)
{
    if (head == NULL || pos < 0)
    {
        return NULL;
    }

    if (pos == 0)
    {
        return deleteDLLHead(head);
    }

    Node *curr = head;

    for (int i = 0; i < pos - 1; i++)
    {
        if (curr->next == NULL)
        {
            return head;
        }
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        return head;
    }

    Node *deleteNode = curr->next;

    curr->next = deleteNode->next;

    if (deleteNode->next != NULL)
        deleteNode->next->prev = curr;
    delete deleteNode;
    return head;
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
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->data < list2->data)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = converArrToLL(arr);
    // Node *tail = getTail(head);

    // int el;
    // cout << "Enter the element: ";
    // cin >> el;

    // printLL(head);
    // head = insertHeadLL(head, el);
    // printLL(head);

    // head = deleteDLLHead(head);
    // cout<<"after the deletion it look's like: ";
    // printLL(head);

    int key;
    cout << "key: ";
    cin >> key;

    // head = deleteAfterLL(head, key);
    // printLL(head);

    // printLL(head);
    // head = deletebeforeLL(head, key);
    // printLL(head);
    int pos;
    cout << "pos: ";
    cin >> pos;
    printLL(head);
    head = deleteAtPos(head, pos);
    printLL(head);


    reverse(head);
    printLL(head);

    freeLL(head);
}
