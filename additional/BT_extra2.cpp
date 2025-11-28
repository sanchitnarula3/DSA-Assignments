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

// Function to create new node
Node* newNode(int val) {
    return new Node(val);
}

// Function to clone tree (to avoid overwriting)
Node* clone(Node* root) {
    if (root == nullptr)
        return nullptr;
    Node* node = new Node(root->data);
    node->left = clone(root->left);
    node->right = clone(root->right);
    return node;
}

// Recursive function to generate all unique BSTs
void generateBSTs(int start, int end) {
    if (start > end)
        return;

    // Try every value as root
    for (int i = start; i <= end; i++) {
        // Generate all left and right subtrees
        cout << "Root: " << i << " | Left subtree: [" << start << "," << i - 1 << "] | Right subtree: [" << i + 1 << "," << end << "]" << endl;
        generateBSTs(start, i - 1);
        generateBSTs(i + 1, end);
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "\nAll structurally unique BST roots:\n";
    generateBSTs(1, n);
    return 0;
}
