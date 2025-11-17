#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
        int data;
        Node* left;
        Node* right;
        Node(int value){
                data = value;
                left = right = NULL;
        }
};

Node* helper (vector <int> &arr, int start, int end){
        if (start > end) return NULL;
        
        int mid = (start + end)/2;
        Node* root = new Node(arr[mid]);
        root-> left = helper(arr, start, mid-1);
        root-> right = helper(arr, mid+1, end);
        return root;
}

Node* array_to_BST(vector <int> &arr, int st, int end){
        Node* root = helper(arr, st, end);
        return root;
}


void inorder(Node* root){

        if(root == NULL)  return;
        inorder(root-> left);
        cout<< root-> data << " ";
        inorder(root-> right);
}

int main(){
        
        vector <int> arr = {10,20,30,40,50,60,70,80,90,100};
        Node* root = array_to_BST(arr,0,arr.size()-1);
        cout << "Here is your Tree\n";
        inorder(root);
        
        return 0;
}



