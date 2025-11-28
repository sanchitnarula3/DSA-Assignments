#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper function to check if a node is a leaf
bool isLeaf(Node* node) {
    return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

// Recursive function to find sum of left leaves
int sumOfLeftLeaves(Node* root) {
    if (root == nullptr)
        return 0;

    int sum = 0;

    // Check if left child is a leaf
    if (isLeaf(root->left))
        sum += root->left->data;

    // Recurse for left and right subtrees
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Utility: Build and test
int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of all left leaves: " << sumOfLeftLeaves(root) << endl;
    return 0;
}
