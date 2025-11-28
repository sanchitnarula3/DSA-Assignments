#include <iostream>
#include <queue>
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

// Function to find right side view using level order traversal
void rightSideView(Node* root, int result[], int &count) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size(); // number of nodes at this level

        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();

            // enqueue left and right children
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            // if this is the last node of the level, store it
            if (i == n - 1)
                result[count++] = node->data;
        }
    }
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    int result[50]; // store right view nodes
    int count = 0;

    rightSideView(root, result, count);

    cout << "Right Side View of Binary Tree: ";
    for (int i = 0; i < count; i++)
        cout << result[i] << " ";

    cout << endl;
    return 0;
}
