/*

#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    vector<int> arr;  // Vector to hold the stack elements
    int top;  // Index of the top element
    int size;  // Size of the stack

    // Constructor
    Stack(int size) {
        this->size = size;
        arr.resize(size);  // Resize the vector to the given size
        top = -1;  // Initialize top to -1 (empty stack)
    }

    // Push operation
    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    // Pop operation
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    // Peek operation
    int peek() {
        if (top >= 0 && top < size) {
            return arr[top];  // Return the top element
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    // Create a stack of size 5
    Stack st(5);

    // Perform operations
    cout << "Pushing elements: " << endl;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Current top element: " << st.peek() << endl;  // Should print 30

    cout << "Popping element: " << endl;
    st.pop();
    cout << "Current top element after pop: " << st.peek() << endl;  // Should print 20

    cout << "Popping more elements: " << endl;
    st.pop();  // Pops 20
    st.pop();  // Pops 10

    // Check if stack is empty
    if (st.isEmpty()) {
        cout << "Stack is now empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}
*/

/*
The two stack questions...

Approach ...->  we should have one array, 2 top bhi chahiye hoga ek top chahiye pehle wale ke liye aur ek top chahiye dusare wale ke liye
aur humye rukna kab hai uske liye size ki bhi to jarurat padegi...

fir jab ye sab ho jaye ga to humm start kaise karenge tab humm ek approach lagayenge ki
                                                    top1 = -1;    |  |  |  |  |  |  |  |  |  |  |  |     top2= size;
                                                    stack 1 starts from here                        stack2 starts from here
                                                    left to right                                     right to left


    then push1 kaise atleast humare paas ek space available hoga abhi to push ho paye ga


#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;
public:
    //Initialization of two stack
    TwoStack(int s){
        this-> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num){
        if(top2 - top1 > 0){ //agar atleast humare top2 aur top1 ke bich ka difference zero se bada hoga tabhi to wo ye darsaye jo  ki humare paas atleast ek empty space bacha huaa has_virtual_destructor
            top1++;//top1 ko humne implement kar diya
            arr[top1] = num ;
        }
        else{
            cout << "space not found ";
        }
    }

    void push2(int num){
        if(top2 - top1 > 0){ //agar atleast humare top2 aur top1 ke bich ka difference zero se bada hoga tabhi to wo ye darsaye ga ki humare paas atleast ek empty space bacha huaa has_virtual_destructor
            top2--;//top2 ko humne implement kar diya aur yeha pe -- ye batata hai ki jab hum top 1 se start karte hai top left to right jate hai aur same iska opposite karte hai top2 ke sath isliye -- lagye hai waha pe

            arr[top2] = num ;
        }
        else{
            cout << "space not found ";
        }
    }

    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            cout<<"the stack is underflow";
        }
    }
    int pop2(){
        if(top2 >= 0){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            cout<<"the stack is underflow";
        }
    }
};
*/

/*
Reverse the string using stack


#include <bits/stdc++.h>
using namespace std;


int main(){
    string str = "aditya";

    stack<char> s;

    for(int i= 0; i< str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout<<"answer is: "<< ans<< " ";

    return 0;
}
*/

/*
Deleting the middle element of the stack




#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, size);
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

int main()
{
    stack<int> inputStack;
    int N;

    cout << "Enter the number of elements in the stack: ";
    cin >> N;

    cout << "Enter the elements of the stack: ";
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        inputStack.push(a); // Fill the stack with input values
    }

    deleteMiddle(inputStack, N);

    cout << "Stack after deleting the middle element: ";
    // Display the stack after deleting the middle element
    while (!inputStack.empty())
    {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;

    return 0;
}
*/

/*
Valid Paranthisis





#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression) {
    stack<char> s;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        // For opening brackets, push to the stack
        if (ch == '{' || ch == '[' || ch == '(') {
            s.push(ch);
        }
        else {
            // If we encounter a closing bracket
            if (!s.empty()) {
                char top = s.top();
                // Check if the current closing bracket matches the top opening bracket
                if ((ch == '}' && top == '{') ||
                    (ch == ')' && top == '(') ||
                    (ch == ']' && top == '[')) {
                    s.pop(); // If it matches, pop the top of the stack
                }
                else {
                    return false; // If it doesn't match, return false
                }
            }
            else {
                return false; // If stack is empty and there's a closing bracket, it's invalid
            }
        }
    }

    // If the stack is empty, all brackets were matched; otherwise, it's invalid
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isValidParenthesis(expression)) {
        cout << "The expression has valid parentheses." << endl;
    }
    else {
        cout << "The expression has invalid parentheses." << endl;
    }

    return 0;
}
*/

/*
Insert in the bottom of the stack

#include <bits/stdc++.h>
using namespace std;

void insertT(stack<int> & myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    //recursive call
    insertT(myStack, x);
    myStack.push(num);

}

stack<int> pushAtBottom(stack<int> & myStack, int x){
    insertT(myStack, x);
    return myStack;
}


int main(){
    int x;
    cin>> x;


}
*/

/*
Reverse a stack using recursion


#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& myStack, int x) {
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    // recursive call
    insertAtBottom(myStack, x);
    myStack.push(num);
}

void reverseStack(stack<int>& myStack) {
    if (myStack.empty()) {
        return;
    }

    int num = myStack.top();
    myStack.pop();

    // recursive call
    reverseStack(myStack);
    insertAtBottom(myStack, num);
}
*/

/*
Sorted Stack


#include <bits/stdc++.h>
using namespace std;

void sortedInsertNumber(stack<int> &s, int num)
{
    if (!s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }

    int sideNum = s.top();
    s.pop();

    // recursive call
    sortedInsertNumber(s, num);
    s.push(sideNum);
}

void sortStack(stack<int> s)
{
    if (s.empty())
    { // jaise hi humara stack empty hota hai wo turant return kardega
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    sortStack(s);

    sortedInsertNumber(s, num);
}
*/


/*
Redundent brackets

((a+b)) -> redundent
(a+b) -> redundent
(c+(a+b)) -> not redundent


#include <bits/stdc++.h>
using namespace std;

bool findRedundentBrackets(string &s){
    stack<int> st;
    for(int i= 0; i< s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            st.push(ch);
        }
        else{
            if(ch == ')'){ //'ch' ya to ')' ye hai ya to lower latter 
            bool isRedudent = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top =='-' || top == '/' || top == '*'){
                        isRedudent = false;
                    }
                    st.pop();
                }
                if(isRedudent == true){
                    return true;
                    st.pop();
                }
            }
        }

    }
}
*/


/*

#include <bits/stdc++.h> 
class NStack
{

    int *arr;
    int *top;
    int *next;

    int n, s;
    int freeSpot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n= N;
        s= S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //for the top initialization

        for(int i= 0; i< n; i++){
            top[i] = -1;
        }

        for(int i= 0; i < s; i++){
            next[i] = i + 1;
        }

        //update last index value to -1
        next[s - 1] = -1;


        //initialization freeSpot
        freeSpot = 0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.

        //check if the spot is having space or not

        if(freeSpot == -1){
            return false;
        }

        int index = freeSpot;
        //update the freeSpot

        freeSpot = next[index];

        //insert element into array
        arr[index] = x;

        //update next;
        next[index] = top[m - 1];

        //update top
        top[m - 1] = index;

        return true; 

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.


        if(top[m - 1] == -1){
            return -1;
        }

        int index = top [m - 1];
        top[m-1] = next;

        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};
*/



