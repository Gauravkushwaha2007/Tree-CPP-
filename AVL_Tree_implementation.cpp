#include <iostream>
#include <stdlib>
using namespace std;

struct Node{
    int data, height;
    Node* left, right;
};

int Height(Node* root){
    if (root == NULL) return 0;
    return max(Height(root-> left), Height(root-> right))+1;
}

int get_Balance (Node* root){
    if (root == NULL) return 0;
    return Height(root-> left)- Height(root-> right);
}

Node* creatNode(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode-> data = value;
    newNode-> left = NULL;
    newNode-> right = NULL;
    newNode-> height = 1;
}

Node* right_rotate(Node* x){
    Node* y = x-> left;
    Node* z = y-> right;

    y-> right = x;
    x-> left = z;
// update height of x and y
    x-> height = max(Heihgt(x->left), Height(x-> right))+1;
    y-> height = max(Heihgt(y->left), Height(y-> right))+1;
    
    return y;
}

Node* left_rotate(Node* y){
    Node* x = y-> left;
    Node* z = x-> right;

    x-> right = y;
    y-> left = z;
//again update height of x and y
    y-> height = max(Heihgt(y->left), Height(y-> right))+1;
    x-> height = max(Heihgt(x->left), Height(x-> right))+1;
    
    return x;
}


Node* insert(Node* root, int key){
    if(root == NULL) return creatNode(key);
    else if (key < root-> data){
        root-> left = insert(root-> left, key);
    }
    else if (key > root-> data){
        root-> right = insert(root-> right, key);
    }
    else {return root; }

    root-> height = 1+ max(Heihgt(root->left), Height(root-> right));
    int balance = get_Balance(root);


}
void inorder (Node* root) {
    if (root == NULL) return;
    inorder(root-> left);
    cout << root-> data << " ";
    inorder(root-> right);
}
