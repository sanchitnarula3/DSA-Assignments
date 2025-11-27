#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* recursiveSearch(Node* root, int key) {
    if (root == nullptr) return nullptr;
    if (root->data == key) return root;
    if (key < root->data) return recursiveSearch(root->left, key);
    return recursiveSearch(root->right, key);
}

Node* iterativeSearch(Node* root, int key) {
    Node* cur = root;
    while (cur != nullptr) {
        if (cur->data == key) return cur;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->left != nullptr) cur = cur->left;
    return cur;
}

Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->right != nullptr) cur = cur->right;
    return cur;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = iterativeSearch(root, key);
    if (target == nullptr) return nullptr;
    if (target->right != nullptr) return findMin(target->right);
    Node* succ = nullptr;
    Node* cur = root;
    while (cur != nullptr) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = iterativeSearch(root, key);
    if (target == nullptr) return nullptr;
    if (target->left != nullptr) return findMax(target->left);
    Node* pred = nullptr;
    Node* cur = root;
    while (cur != nullptr) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    for (int k: keys) root = insert(root, k);

    int s = 40;
    Node* r1 = recursiveSearch(root, s);
    cout << "Recursive search " << s << ": " << (r1 ? "Found" : "Not Found") << "\n";

    int s2 = 65;
    Node* r2 = iterativeSearch(root, s2);
    cout << "Iterative search " << s2 << ": " << (r2 ? "Found" : "Not Found") << "\n";

    Node* mn = findMin(root);
    Node* mx = findMax(root);
    cout << "Minimum element: " << (mn ? mn->data : -1) << "\n";
    cout << "Maximum element: " << (mx ? mx->data : -1) << "\n";

    int key = 50;
    Node* succ = inorderSuccessor(root, key);
    Node* pred = inorderPredecessor(root, key);
    if (succ) cout << "In-order successor of " << key << " is " << succ->data << "\n";
    else cout << "In-order successor of " << key << " does not exist\n";
    if (pred) cout << "In-order predecessor of " << key << " is " << pred->data << "\n";
    else cout << "In-order predecessor of " << key << " does not exist\n";

    return 0;
}
