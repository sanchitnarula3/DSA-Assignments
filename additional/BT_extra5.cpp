#include <iostream>
using namespace std;

// Define Node structure
class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to search for index of root in inorder
int search(char inorder[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build tree
Node* buildTree(char inorder[], char preorder[], int inStart, int inEnd, int &preIndex) {
    if (inStart > inEnd)
        return nullptr;

    // Pick current node from Preorder
    char curr = preorder[preIndex++];
    Node* node = new Node(curr);

    // If this node has no children
    if (inStart == inEnd)
        return node;

    // Find index of this node in inorder
    int inIndex = search(inorder, inStart, inEnd, curr);

    // Build left and right subtrees recursively
    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Function to print Postorder traversal (to check correctness)
void postorder(Node* root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char preorder[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    int preIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, n - 1, preIndex);

    cout << "Postorder traversal of constructed tree: ";
    postorder(root);
    cout << endl;

    return 0;
}
