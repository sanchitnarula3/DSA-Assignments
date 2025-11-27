#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

void displayWithRepeat(Node* head) {
    if (head == nullptr) return;

    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);

    cout << head->data; 
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    head->next->next->next->next = new Node(60);
    head->next->next->next->next->next = head;

    displayWithRepeat(head);

    return 0;
}
