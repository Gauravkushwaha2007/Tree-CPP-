#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = right= NULL;
    }
};

// Traversals--- DFS---> 1. inorder(left, root, right)
void inorder (Node* root){
    if (root == NULL) return;
    inorder(root-> left);
    cout<< root-> data << " ";
    inorder(root-> right);
}

// Treaversals ---- DFS---> 2. Preorder(root, left, right)
void preorder (Node* root){
    if (root== NULL) return;
    cout<< root-> data << " ";
    preorder(root-> left);
    preorder(root-> right);
}

// Traversals-- DFS---> 3. Postorder(left, right, root)
void postorder (Node* root){
    if (root == NULL) return;
    postorder(root-> left);
    postorder(root-> right);
    cout<< root-> data<< " ";
}

int main(){
    Node* root = new Node(1);
    root-> left = new Node(2);
    root-> right = new Node(3);
    root-> left-> left = new Node(4);
    root-> left-> right = new Node(5);

    cout<< "Tree in the order of Preorder\n";
    preorder(root); cout<< endl;

    cout<< "Tree in the order of Postorder\n";
    postorder(root); cout<< endl;

    cout<< "Tree in the order of inorder\n";
    inorder(root); cout<< endl;

    return 0;
}

