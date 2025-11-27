#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char c) : data(c), prev(nullptr), next(nullptr) {}
};

Node* buildFromString(const string &s) {
    if (s.empty()) return nullptr;
    Node* head = new Node(s[0]);
    Node* tail = head;
    for (size_t i = 1; i < s.size(); ++i) {
        Node* n = new Node(s[i]);
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    return head;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;
    Node* tail = head;
    while (tail->next != nullptr) tail = tail->next;
    Node* left = head;
    Node* right = tail;
    while (left != right && left->prev != right) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter string (characters only): ";
    getline(cin, s);
    Node* head = buildFromString(s);
    if (isPalindrome(head)) cout << "Palindrome\n"; else cout << "Not Palindrome\n";
    return 0;
}
