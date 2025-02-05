#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        
        this-> left = NULL;

        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int DTI){
    if(root == NULL){
        return new Node(DTI);
    }

    if(DTI > root->data){
        root->right = insertIntoBST(root->right, DTI);
    }
    else if(DTI < root->data){
        root->left = insertIntoBST(root->left, DTI);
    }
    return root;
}

Node* nodeToDelete(Node* root, int key){
    if(root == NULL){
        return root;
    }

    if(root->data == key){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right != NULL){
            Node* minNode = findMin(root->right);
            root->data = minNode->data;
            root->right = nodeToDelete(root->right, minNode->data);
            return root;
        }
    }

    else if(root->data > key){
        root->left = nodeToDelete(root->left, key);
    }
    else{
        root->right = nodeToDelete(root->right, key);
    }
    return root;
}

Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

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

Node* takeInput(Node* root){
    int data;
    cin>> data;

    while(data!= -1){
        root = insertIntoBST(root, data);
        cin>> data;
    }
    return root;
}

int main(){
    Node* root = NULL;

    cout<< "Enter the data to create the BST (enter -1 to stop): "<<endl;

    root = takeInput(root);

    cout<< "printing the level order traversal of the BST: "<< endl;

    levelOrderTraversal(root);
}




