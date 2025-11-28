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

// 🔁 Function to rotate the list to the left by k positions
Node* rotate(Node* head, int k)
{
    if (!head || !head->next || k == 0)
        return head; // nothing to rotate

    for (int i = 0; i < k; i++)
    {
        Node* temp1 = head;   // first node
        Node* temp2 = head;   // to reach last node

        // Move head to second node
        head = head->next;

        // Find last node
        while (temp2->next != NULL)
            temp2 = temp2->next;

        // Connect last node to old head (temp1)
        temp2->next = temp1;

        // Break link of new last node
        temp1->next = NULL;
    }

    return head;
}


int main() {
    LinkedList list;
    for (int i = 1; i <= 5; i++)
        list.append(i);

    cout << "Original List: ";
    list.printList();

    int k = 2;
    list.head = rotateLeft(list.head, k);

    cout << "After rotating left by " << k << " positions:\n";
    list.printList();

    return 0;
}
