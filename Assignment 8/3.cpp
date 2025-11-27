#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insertNode(root->left, key);
    else if (key > root->data) root->right = insertNode(root->right, key);
    return root;
}

Node* findMin(Node* root) {
    Node* cur = root;
    while (cur->left != nullptr) cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) return nullptr;
        else if (root->left == nullptr) return root->right;
        else if (root->right == nullptr) return root->left;
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) return 1 + minDepth(root->right);
    if (root->right == nullptr) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insertNode(root, v);

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 70);

    cout << "After deletion: ";
    inorder(root);
    cout << "\n";

    cout << "Maximum depth: " << maxDepth(root) << "\n";
    cout << "Minimum depth: " << minDepth(root) << "\n";

    return 0;
}
