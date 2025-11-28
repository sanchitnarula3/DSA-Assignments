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
    LinkedList() {
        head = NULL;
    }

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

    // Function to detect and remove loop
    void removeLoop() {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Loop detected!\n";
                break;
            }
        }

        // No loop
        if (fast == NULL || fast->next == NULL) {
            cout << "No loop found.\n";
            return;
        }

        // Step 2: Find start of loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        Node* loopStart = slow;

        // Step 3: Find last node of loop and break it
        Node* temp = loopStart;
        while (temp->next != loopStart)
            temp = temp->next;

        temp->next = NULL;
        cout << "Loop removed at node with data: " << loopStart->data << "\n";
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    // Create a loop for testing: 5 → 3
    list.head->next->next->next->next->next = list.head->next->next;

    list.removeLoop();
    list.printList();

    return 0;
}
