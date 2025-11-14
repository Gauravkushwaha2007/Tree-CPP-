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

static int index = -1;

Node* build_tree(vector<int> &preOrder) {
    index++;
    if (preOrder[index]== -1) return NULL;
    Node* root = new Node(preOrder[index]);
    root-> left = build_tree(preOrder);
    root-> right = build_tree(preOrder);
    return root;

}

void display(Node* root){
    if (root == NULL) return;
    cout<< root->data << "\n";
    display(root-> left);
    display(root-> right);
}

int main(){
    vector <int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = build_tree(preOrder);
    display(root);
    return 0;
}
