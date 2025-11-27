#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

void dInsertFirst(DNode* &head, int val) {
    DNode* node = new DNode(val);
    if (head == nullptr) {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void dInsertLast(DNode* &head, int val) {
    DNode* node = new DNode(val);
    if (head == nullptr) {
        head = node;
        return;
    }
    DNode* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = node;
    node->prev = cur;
}

bool dInsertAfter(DNode* &head, int key, int val) {
    DNode* cur = head;
    while (cur != nullptr && cur->data != key) cur = cur->next;
    if (cur == nullptr) return false;
    DNode* node = new DNode(val);
    node->next = cur->next;
    node->prev = cur;
    if (cur->next) cur->next->prev = node;
    cur->next = node;
    return true;
}

bool dInsertBefore(DNode* &head, int key, int val) {
    DNode* cur = head;
    while (cur != nullptr && cur->data != key) cur = cur->next;
    if (cur == nullptr) return false;
    if (cur == head) {
        dInsertFirst(head, val);
        return true;
    }
    DNode* node = new DNode(val);
    node->prev = cur->prev;
    node->next = cur;
    cur->prev->next = node;
    cur->prev = node;
    return true;
}

bool dDeleteNode(DNode* &head, int key) {
    if (head == nullptr) return false;
    DNode* cur = head;
    while (cur != nullptr && cur->data != key) cur = cur->next;
    if (cur == nullptr) return false;
    if (cur == head) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete cur;
        return true;
    }
    if (cur->next) cur->next->prev = cur->prev;
    if (cur->prev) cur->prev->next = cur->next;
    delete cur;
    return true;
}

bool dSearch(DNode* head, int key) {
    DNode* cur = head;
    while (cur != nullptr) {
        if (cur->data == key) return true;
        cur = cur->next;
    }
    return false;
}

void dDisplay(DNode* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    DNode* cur = head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << "\n";
}


struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

void cDisplay(CNode* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    CNode* cur = head;
    do {
        cout << cur->data;
        cur = cur->next;
        if (cur != head) cout << " -> ";
    } while (cur != head);
    cout << "\n";
}

void cInsertFirst(CNode* &head, int val) {
    CNode* node = new CNode(val);
    if (head == nullptr) {
        node->next = node;
        head = node;
        return;
    }
    CNode* last = head;
    while (last->next != head) last = last->next;
    node->next = head;
    last->next = node;
    head = node;
}

void cInsertLast(CNode* &head, int val) {
    CNode* node = new CNode(val);
    if (head == nullptr) {
        node->next = node;
        head = node;
        return;
    }
    CNode* last = head;
    while (last->next != head) last = last->next;
    last->next = node;
    node->next = head;
}

bool cInsertAfter(CNode* &head, int key, int val) {
    if (head == nullptr) return false;
    CNode* cur = head;
    do {
        if (cur->data == key) {
            CNode* node = new CNode(val);
            node->next = cur->next;
            cur->next = node;
            return true;
        }
        cur = cur->next;
    } while (cur != head);
    return false;
}

bool cInsertBefore(CNode* &head, int key, int val) {
    if (head == nullptr) return false;
    if (head->data == key) {
        cInsertFirst(head, val);
        return true;
    }
    CNode* prev = head;
    CNode* cur = head->next;
    while (cur != head) {
        if (cur->data == key) {
            CNode* node = new CNode(val);
            prev->next = node;
            node->next = cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

bool cDeleteNode(CNode* &head, int key) {
    if (head == nullptr) return false;
    if (head->next == head) {
        if (head->data == key) {
            delete head;
            head = nullptr;
            return true;
        }
        return false;
    }
    if (head->data == key) {
        CNode* last = head;
        while (last->next != head) last = last->next;
        CNode* t = head;
        head = head->next;
        last->next = head;
        delete t;
        return true;
    }
    CNode* prev = head;
    CNode* cur = head->next;
    while (cur != head) {
        if (cur->data == key) {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

bool cSearch(CNode* head, int key) {
    if (head == nullptr) return false;
    CNode* cur = head;
    do {
        if (cur->data == key) return true;
        cur = cur->next;
    } while (cur != head);
    return false;
}


int main() {
    DNode* dHead = nullptr;
    CNode* cHead = nullptr;

    while (true) {
        cout << "\n==== Choose List Type ====\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Singly Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        int type;
        cin >> type;

        if (type == 0) break;

        if (type == 1) {
            while (true) {
                cout << "\n-- Doubly Linked List Menu --\n";
                cout << "1. Insert at first\n2. Insert at last\n3. Insert after a node\n4. Insert before a node\n";
                cout << "5. Delete a node\n6. Search\n7. Display\n8. Back\n";
                cout << "Enter option: ";
                int opt; 
                cin >> opt;
                if (opt == 8) break;
                int v, key;
                bool res;
                switch(opt) {
                    case 1: cin >> v; dInsertFirst(dHead, v); break;
                    case 2: cin >> v; dInsertLast(dHead, v); break;
                    case 3: cin >> key >> v; res = dInsertAfter(dHead, key, v); if(!res) cout<<"Key not found\n"; break;
                    case 4: cin >> key >> v; res = dInsertBefore(dHead, key, v); if(!res) cout<<"Key not found\n"; break;
                    case 5: cin >> key; res = dDeleteNode(dHead, key); if(!res) cout<<"Not found\n"; break;
                    case 6: cin >> key; cout << (dSearch(dHead, key) ? "Found\n" : "Not found\n"); break;
                    case 7: dDisplay(dHead); break;
                }
            }
        }

        else if (type == 2) {
            while (true) {
                cout << "\n-- Circular List Menu --\n";
                cout << "1. Insert at first\n2. Insert at last\n3. Insert after a node\n4. Insert before a node\n";
                cout << "5. Delete\n6. Search\n7. Display\n8. Back\n";
                cout << "Enter option: ";
                int opt; 
                cin >> opt;
                if (opt == 8) break;
                int v, key;
                bool res;
                switch(opt) {
                    case 1: cin >> v; cInsertFirst(cHead, v); break;
                    case 2: cin >> v; cInsertLast(cHead, v); break;
                    case 3: cin >> key >> v; res = cInsertAfter(cHead, key, v); if(!res) cout<<"Key not found\n"; break;
                    case 4: cin >> key >> v; res = cInsertBefore(cHead, key, v); if(!res) cout<<"Key not found\n"; break;
                    case 5: cin >> key; res = cDeleteNode(cHead, key); if(!res) cout<<"Not found\n"; break;
                    case 6: cin >> key; cout << (cSearch(cHead, key) ? "Found\n" : "Not found\n"); break;
                    case 7: cDisplay(cHead); break;
                }
            }
        }
    }

    return 0;
}
