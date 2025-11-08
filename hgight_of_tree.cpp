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
    left_height = count(root->left);
    right_height = count(root->right);
    return (left_height + right_height +1);
}

// Sum of All nodes values exist in Tree
int sum_of_tree(Node* root){
    if (root == NULL) return 0;
    left_sum = sum_of_tree(root-> left);
    right_sum = sum_of_tree(root-> right);
    return left_sum + right_sum + root-> data;
}

// Total level exist in a Tree
int height_of_tree (Node* root){
    if (root == NULL) return 0;
    left_count = height_of_tree(root->left);
    right_count = height_of_tree(root->right);
    return (max(left_count, right_count) +1);
}

