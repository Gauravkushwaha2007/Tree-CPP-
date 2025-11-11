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
        
int main(){
        vector <int> arr = {10,20,50,60,80,100);
        Node* root = buildBST(arr);
        display(root);

 return 0;
}

            
