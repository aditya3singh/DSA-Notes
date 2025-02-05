#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

/*

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
*/

void levelOrderTraversal(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}


//Diameter in Binary Search tree

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;

    return ans;
}

int diameterOfBT(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int leftDiameter = diameterOfBT(root->left);
    int rightDiameter = diameterOfBT(root->right);

    int ans = max(leftDiameter, max(rightDiameter, leftHeight + rightHeight));
    return ans;
}




int main()
{
    Node *root = NULL;
    // creating a tree...
    root = buildTree(root);
    // 1 3 7 -1  -1 11 -1 -1 5 17 -1 -1 -1
    cout<<endl;
    levelOrderTraversal(root);



    cout<< diameterOfBT(root);
    cout<< height(root);
}