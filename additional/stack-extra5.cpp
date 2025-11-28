#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

// Function to add two polynomial linked lists
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* resultHead = NULL;
    Node* resultTail = NULL;

    // Traverse both lists
    while (poly1 != NULL && poly2 != NULL) {
        Node* temp = NULL;

        if (poly1->pow == poly2->pow) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            temp = new Node(sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            temp = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            temp = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }

        // Attach new node to result list
        if (resultHead == NULL) {
            resultHead = temp;
            resultTail = temp;
        } else {
            resultTail->next = temp;
            resultTail = temp;
        }
    }

    // Add remaining terms (if any)
    while (poly1 != NULL) {
        Node* temp = new Node(poly1->coeff, poly1->pow);
        resultTail->next = temp;
        resultTail = temp;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        Node* temp = new Node(poly2->coeff, poly2->pow);
        resultTail->next = temp;
        resultTail = temp;
        poly2 = poly2->next;
    }

    return resultHead;
}

// Function to print polynomial
void printPolynomial(Node* head) {
    while (head != NULL) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next != NULL) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Polynomial 1: 5x^2 + 4x^1 + 2
    Node* poly1 = new Node(5, 2);
    poly1->next = new Node(4, 1);
    poly1->next->next = new Node(2, 0);

    // Polynomial 2: 5x^1 + 5
    Node* poly2 = new Node(5, 1);
    poly2->next = new Node(5, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);
    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);

    cout << "Sum: ";
    printPolynomial(sum);

    return 0;
}
