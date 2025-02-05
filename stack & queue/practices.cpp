/*
1. Write a C++ program to implement a stack using an array with push and pop operations. Find the top element of the stack and check if the stack is empty or not.
Test Data:
Create a stack object:
Check the stack is empty or not? 1
Insert some elements onto the stack:
Stack elements: 4 5 6 7
Remove an element from the stack! 4
Stack elements: 5 6 7
Top of the element of the stack:
5


#include <bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int arr[MAX_PATH];

    public:
    Stack(){
        top = -1;
    }

    void push(int el){
        if(top >= (MAX_PATH - 1)){
            cout <<" Stack is overflow ";
        }
        else{
            arr[++top] = el;
            cout<< el<< "push out the stack ";
        }
    }


    int pop(){
        if(top < 0){
            cout << "stack is underflow";
            return -1;
        }else{
            return arr[--top];
        }
    }


    int peek(){
        if(top < 0){
            cout <<"stack is empty ";
            return -1;
        }
        else{
            return arr[top];
        }
    }

    bool isEmpty(){
        return (top<0);
    }
};
*/

/*
2. Write a C++ program to implement a stack using an array with push and pop operations. Check if the stack is full.
Test Data:
MAX_SIZE of the array: 5
Insert some elements onto the stack:
Stack elements: 1 2 5 6 9
Is the stack full? 1
Remove an element from the stack! 1
Stack elements: 2 5 6 9
Is the stack full? 0



#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 5

class Stack
{
private:
    int arr[MAX_SIZE]; // Array to hold stack elements
    int top;

public:
    Stack() : top(-1) {}

    void push(int el)
    {
        if(isFull()){
            cout << "the is overFlow "<<endl;
        }
        else{
            arr[++top] = el;
            cout << el<< " ";
        }
    }

    void pop(){
        if(isEmpty()){
            cout<< "the stack is underflow "<<endl;
            return;
        }
        else{
            cout<<arr[top]<<endl;
            top--;
        }
    }

    int peek(){
        return arr[top];
    }

    bool isFull(){
        return top == MAX_SIZE - 1;

    }

    bool isEmpty(){
        return top == -1;
    }

    void display(){
        if(isEmpty()){
            cout<< "stack is empty "<< endl;
        }else{
            cout<<"Stack elements ->";
            for(int i= 0; i<= top; i++){
                cout<<arr[i]<< " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout<< endl;
    stack.display();

    cout << "the element is full or Not-> "<<stack.isFull()<<endl;
    stack.isEmpty();

    cout<< "the peek element in the satck is ->"<<stack.peek()<<endl;
    stack.push(6);

    cout<< "the peek element in the satck is ->"<<stack.peek()<<endl;
    stack.pop();
    cout<< "the peek element in the satck is ->"<<stack.peek()<<endl;
}
*/

/*

3. Write a C++ program to sort a given stack (using an array) using another stack.
Test Data:
Input some elements onto the stack:
Stack elements: 0 1 5 2 4 7
Sort the elements in the stack:`
Display the sorted elements of the stack:
Stack elements: 0 1 2 4 5 7
Remove two elements:
Stack elements: 2 4 5 7
Input two more elements
Stack elements: 10 -1 2 4 5 7
Sort the elements in the stack:
Display the sorted elements of the stack:
Stack elements: -1 2 4 5 7 10


#include <bits/stdc++.h>
using namespace std;

void SortInsertNumber(stack<int> &stk, int num){
    if(stk.empty() || (!stk.empty() && stk.top() > num)){
        stk.push(num);
        return;
    }

    int sideNum = stk.top();
    stk.pop();

    SortInsertNumber(stk, num);
    stk.push(sideNum);
}

void sortStack(stack<int> &stk){
    if(stk.empty()){
        return;
    }

    int num = stk.top();
    stk.pop();

    sortStack(stk);

    SortInsertNumber(stk, num);

}


int main(){
    stack<int> stk;

    int size;
    cout << "Size:-> ";
    cin>> size;

    int arr[size];

    for(int i= 0; i< size; i++){
        cin>> arr[i];
        stk.push(arr[i]);
    }

    sortStack(stk);

    for(int i= 0; i<size ; i++){
        // stk.push(arr[i]);
        cout<< arr[i]<< endl;
    }

    return 0;
}
*/

/*

4. Write a C++ program that reverses the stack (using an array) elements.
Test Data:
Input some elements onto the stack:
Stack elements: 0 1 5 2 4 7
Display the reverse elements of the stack:
Stack elements: 7 4 2 5 1 0
Remove two elements:
Stack elements: 2 5 1 0
Input two more elements
Stack elements: 10 -1 2 5 1 0
Display the reverse elements of the stack:
Stack elements: 0 1 5 2 -1 10


#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int size;
    cout << "size:-> ";
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        st.push(arr[i]);
    }

    int max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max;
}
*/

#include <bits/stdc++.h>
using namespace std;

class StackIm
{
private:
    int arr[5];
    int top;

public:
    StackIm() : top(-1) {}

    int getTop() const
    {
        return top;
    }

    void push(int el)
    {
        if (top == 4)
        {
            cout << "Stack is overflow" << endl;
        }
        else
        {
            arr[++top] = el;
            cout << el << " pushed into the stack" << endl;
        }
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack is underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    bool isFull()
    {
        return (top == 4);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

void pushEL(StackIm &stk, int el)
{
    stk.push(el);
}

int main()
{
    StackIm stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.display();

    cout << "Is the stack full? " << stk.isFull() << endl;
    cout << "Top element of the stack: " << stk.peek() << endl;

    stk.pop();
    stk.display();

    stk.push(6);
    stk.display();

    return 0;
}
