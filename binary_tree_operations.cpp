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

// Total nodes in a whole Tree
int count(Node* root){
    if (root ==  NULL) return 0;
    int left_count  = count(root->left);
    int right_count = count(root->right);
    return (left_count + right_count +1);
}

// Sum of All nodes values exist in Tree
int sum_of_tree(Node* root){
    if (root == NULL) return 0;
    int left_sum = sum_of_tree(root-> left);
    int right_sum = sum_of_tree(root-> right);
    return left_sum + right_sum + root-> data;
}

// Total level exist in a Tree
int height_of_tree (Node* root){
    if (root == NULL) return 0;
    int left_height= height_of_tree(root->left);
    int right_height  = height_of_tree(root->right);
    return (max(left_height, right_height) +1);
}

//Diameter of Tree
int diameter (Node* root){
    if (root== NULL) return 0;
    int left_diameter = diameter(root->left);
    int right_diameter  = diameter(root->right);
    int curr_diameter = height_of_tree(root-> left)+ height_of_tree(root-> right) +1;
    return (max(curr_diameter,max(left_diameter, right_diameter)));

}

//Show all Roots data at a specific Level
void kth_Level(Node*root, int k){
    if (root==NULL) return;
    if(k == 1){
        cout<< root-> data<< " ";
    }
    kth_Level(root-> left, k-1);
    kth_Level(root-> right, k-1);
}

// Transform to sum tree(All nodes will treansform with the sum of Left and Right node value+ itself sum
int Transform (Node* root){
    if(root == NULL) return 0;
    int left_trans = Transform(root-> left);
    int right_trans = Transform(root-> right);
    root-> data += left_trans+ right_trans;
    return root-> data;
}

// For building Tree we can create a function of Buld tree
Node* buildTree(){
    int data; 
    cout << "Enter your data: ";
    cin >> data;
    if (data == -1) return NULL;
    Node* root = new Node(data);
    root-> left = buildTree();
    root-> right = buildTree();
    return root;
}

void display(Node* root) {
    if(root ==NULL) return;
    cout<< root-> data << " ";
    display(root-> left);
    display(root-> right);
}




int main() {
    Node* root = buildTree();
    cout<< "Your Tree is: ";
    display(root);
    return 0;
}

