#include <iostream>
#include <vector>
using namespace std;

class Node{
        public:
        int data;
        Node* left;
        Node* right;
        Node(int value){
                data = value;
                left = right = NULL;
        }
};

Node* insert(Node* root, int val){
        if (root == NULL) return new Node(val);
        if (val < root-> data){
                root-> left = insert(root-> left, val);
        }
        else{ 
                root-> right = insert(root-> right, val);
        }
        return root;
}


Node* buildBST(vector <int> arr) {
        Node* root = NULL;
        for (int val : arr){
                root = insert(root, val);
        }
        return root;
}

void display (Node* root){  //PreOrder Traversal
        if(root == NULL) return;
        cout<< root-> data;
        display(root-> left);
        display(root-> right);
}

// Deletion method

// Gettign inorder successor 
Node* inorderSuccessor (Node* root){
        Node* successor = root;
        while(successor-> left != NULL){
                successor = successor-> left;
        }
        return successor;
}

Node* deleteNode(Node* root, int key){
        if(root == NULL) return root;
        else if (key < root-> data){
                root-> left = deleteNode(root-> left,key);
        }
        else if (key > root-> data){
                root-> right = deleteNode(root-> right, key);
        }
        else{ // case when root-> data == key
                //casse 1 when 0 child
                if(root-> left == NULL && root-> right == NULL){
                        delete root;
                        return NULL;
                }
                //case 2 when right child
                else if(root->left == NULL){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }

                //case 2 when left child
                else if(root-> right == NULL){
                        Node* temp = root-> left;
                        delete root;        //memory free 
                        return temp;
                }
                //case 3 when left and right both child
                else{
                        Node* successor = inorderSuccessor(root-> right);
                        root-> data = successor-> data;
                        root-> right = deleteNode(root-> right, successor-> data);
                }
        }
        return root;
}


int main(){
        vector <int> arr = {10,20,50,60,80,100};
        Node* root = buildBST(arr);
        display(root);
        root = deleteNode(root, 50);
        cout<< " After deletion 50";
        display(root);
 return 0;
}

            
