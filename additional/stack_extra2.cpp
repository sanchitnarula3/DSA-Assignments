#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// 🔁 Iterative function to reverse list in groups of K
Node* reverseInGroups(Node* head, int k) {
    if (!head || k == 1)
        return head;

    // Step 1: Count total nodes
    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    int groups = n / k; // Number of complete groups
    Node* dummy = new Node(0); // Dummy node for easy head handling
    dummy->next = head;

    Node* prevGroupEnd = dummy;
    Node* curr = head;
    Node* next = NULL;

    // Step 2: Reverse 'groups' times
    for (int g = 0; g < groups; g++) {
        Node* last = curr;  // last node of current group (will become end after reversal)
        Node* prev = NULL;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect reversed group
        prevGroupEnd->next = prev; // prev is new head of reversed group
        last->next = curr;         // connect to next group
        prevGroupEnd = last;       // move pointer
    }

    return dummy->next;
}

int main() {
    LinkedList list;
    for (int i = 1; i <= 8; i++)
        list.append(i);

    cout << "Original List: ";
    list.printList();

    int k = 3;
    list.head = reverseInGroups(list.head, k);

    cout << "Reversed in groups of " << k << ": ";
    list.printList();

    return 0;
}
