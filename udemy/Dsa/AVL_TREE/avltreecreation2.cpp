#include <iostream>
using namespace std;

class Node {
public:
    int data, height;
    Node* lchild, *rchild;
    
    Node(int data) {
        this->data = data;
        this->height = 1;
        lchild = rchild = nullptr;
    }
};

int height(Node* root) {
    if (root == nullptr) return 0;
    return root->height;
}

int balanceFactor(Node* root) {
    return height(root->lchild) - height(root->rchild);
}

Node* LLRotation(Node* p) {
    Node* pl = p->lchild;
    p->lchild = pl->rchild;
    pl->rchild = p;
    p->height = max(height(p->lchild), height(p->rchild)) + 1;
    pl->height = max(height(pl->lchild), height(pl->rchild)) + 1;
    return pl;
}

Node* RRRotation(Node* p) {
    Node* pr = p->rchild;
    p->rchild = pr->lchild;
    pr->lchild = p;
    p->height = max(height(p->lchild), height(p->rchild)) + 1;
    pr->height = max(height(pr->lchild), height(pr->rchild)) + 1;
    return pr;
}

Node* LRRotation(Node* p) {
    p->lchild = RRRotation(p->lchild);
    return LLRotation(p);
}

Node* RLRotation(Node* p) {
    p->rchild = LLRotation(p->rchild);
    return RRRotation(p);
}

Node* insertNode(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->lchild = insertNode(root->lchild, val);
    } else if (val > root->data) {
        root->rchild = insertNode(root->rchild, val);
    }

    // Update the height of this ancestor node
    root->height = max(height(root->lchild), height(root->rchild)) + 1;

    // Get the balance factor of this ancestor node to check if it became unbalanced
    int balance = balanceFactor(root);

    // Left heavy (Left-Left Case)
    if (balance > 1 && val < root->lchild->data) {
        return LLRotation(root);
    }

    // Right heavy (Right-Right Case)
    if (balance < -1 && val > root->rchild->data) {
        return RRRotation(root);
    }

    // Left-Right Case
    if (balance > 1 && val > root->lchild->data) {
        return LRRotation(root);
    }

    // Right-Left Case
    if (balance < -1 && val < root->rchild->data) {
        return RLRotation(root);
    }

    // Return the (possibly updated) root pointer
    return root;
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << "\t" << root->data;
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->lchild);
    cout << "\t" << root->data;
    inorder(root->rchild);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout << "\t" << root->data;
}

void display(Node* root) {
    cout << "\n\n\n\t\tThe inorder traversal of the tree is\n\n\t\t\t\t:";
    inorder(root);
    cout << "\n\n\n\t\tThe preorder traversal of the tree is\n\n\t\t\t\t:";
    preorder(root);
    cout << "\n\n\n\t\tThe postorder traversal of the tree is\n\n\t\t\t\t:";
    postorder(root);
}

int main() {
    Node* root = nullptr;
    
    cout << "\n\n\t\t-------------Creating the tree--------------";

    // Insert nodes into the AVL tree and update the root
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 1);

    // Display the tree traversals
    display(root);

    return 0;
'/
'}
