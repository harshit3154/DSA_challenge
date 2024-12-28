#include <iostream>
using namespace std;

struct Node {
    Node *lchild, *rchild;
    int data, height;
};

Node* root = nullptr;

void display(Node *root){
    cout<<"\n\n\n\t\tThe node data are : ";
    cout << "\n\n\t\t\t\tThe value of root is : " << root->data;
    cout<<"\n\n\t\t\t\tThe left child is : "<<root->lchild->data;
    cout<<"\n\n\t\t\t\tThe right child is : "<<root->rchild->data;
}

// Function to get height of a node
int NodeHeight(Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return max(hl, hr) + 1;
}

// Function to get balance factor of a node
int BalanceFactor(Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

// LL Rotation
Node* LLRotation(Node *p) {
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p) root = pl;
    return pl;
}

// RR Rotation
Node* RRRotation(Node *p) {
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p) root = pr;   
    return pr;
}

// LR Rotation
Node* LRRotation(Node *p) {
    p->lchild = RRRotation(p->lchild);
    return LLRotation(p);
}

// RL Rotation
Node* RLRotation(Node *p) {
    p->rchild = LLRotation(p->rchild);
    return RRRotation(p);
}

// Recursive insertion with balancing
Node* RInsert(Node *p, int data) {
    if (!p) {
        Node *t = new Node;
        t->data = data;
        t->height = 1;
        t->lchild = t->rchild = nullptr;
        return t;
    }

    if (data < p->data)
        p->lchild = RInsert(p->lchild, data);
    else if (data > p->data)
        p->rchild = RInsert(p->rchild, data);

    p->height = NodeHeight(p);

    

    int bf = BalanceFactor(p);
    if (bf == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    if (bf == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    if (bf == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    if (bf == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

int main() {
    cout << "\t\t\t____________Welcome to AVL Tree Lesson_____________________";
    root = RInsert(root, 4);
    root = RInsert(root, 3);
    root = RInsert(root, 2);

    display(root);
    return 0;
}
