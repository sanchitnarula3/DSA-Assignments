#include <iostream>
using namespace std;

// Node of BST
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

// Node of Doubly Linked List
class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

// ---------- STEP 1: Inorder Traversal and Store in Array ----------
void inorder(Node* root, int arr[], int &index) {
    if (root == nullptr)
        return;
    inorder(root->left, arr, index);
    arr[index++] = root->data;
    inorder(root->right, arr, index);
}

// ---------- STEP 2: Merge Two Sorted Arrays ----------
int mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < n1)
        merged[k++] = arr1[i++];
    while (j < n2)
        merged[k++] = arr2[j++];

    return k;  // total elements in merged[]
}

// ---------- STEP 3: Convert Sorted Array to Doubly Linked List ----------
DLLNode* arrayToDLL(int merged[], int n) {
    if (n == 0) return nullptr;

    DLLNode* head = new DLLNode(merged[0]);
    DLLNode* curr = head;

    for (int i = 1; i < n; i++) {
        DLLNode* temp = new DLLNode(merged[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}

// ---------- STEP 4: Display Doubly Linked List ----------
void printDLL(DLLNode* head) {
    DLLNode* temp = head;
    cout << "Doubly Linked List (sorted): ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ---------- Helper: Insert into BST ----------
Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// ---------- MAIN ----------
int main() {
    Node* root1 = nullptr;
    Node* root2 = nullptr;

    // First BST
    root1 = insert(root1, 30);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);

    // Second BST
    root2 = insert(root2, 10);
    root2 = insert(root2, 25);
    root2 = insert(root2, 35);
    root2 = insert(root2, 50);

    int arr1[50], arr2[50], merged[100];
    int n1 = 0, n2 = 0;

    inorder(root1, arr1, n1);
    inorder(root2, arr2, n2);

    int total = mergeArrays(arr1, n1, arr2, n2, merged);

    DLLNode* head = arrayToDLL(merged, total);

    printDLL(head);

    return 0;
}
