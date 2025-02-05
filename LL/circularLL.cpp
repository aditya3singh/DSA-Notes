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
        next = NULL;
    }
};

Node *insertInEmptyList(Node *&last, int el)
{
    if (last == NULL)
    {
        Node *temp = new Node(el);
        temp->next = temp;
        return temp;
    }
    return last;
}

void printLL(Node *&last)
{
    if (last == NULL)
        return;

    Node *temp = last;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last);
    cout << endl;
}




int main()
{
    Node *last = nullptr;

    // Insert a node into the empty list
    last = insertInEmptyList(last, 1);
    printLL(last);

    int el;
    cout << "Enter the element: ";
    cin >> el;
    if (last == nullptr)
    {
        last = insertInEmptyList(last, el);
    }

    // Print the list
    cout << "List after insertion: ";
    printLL(last);

    return 0;
}
