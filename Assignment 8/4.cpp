#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }

    bool isBST(node* root, long long minVal, long long maxVal)
    {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isBST(root->left, minVal, root->val) &&
               isBST(root->right, root->val, maxVal);
    }
};

int main()
{
    node *help = new node(0);

    node *a = new node(10);
    node *b = new node(5);
    node *c = new node(15);
    node *d = new node(2);
    node *e = new node(8);
    node *f = new node(11);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;

    if (help->isBST(a, LLONG_MIN, LLONG_MAX))
        cout << "the given tree is a BST";
    else
        cout << "not a BST";

    return 0;
}
