#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lchild, *rchild;
};

struct Node *root = NULL;

void insert(int x) {
    struct Node *t = root, *p, *r;
    if (t == NULL) {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data = x;
        root->lchild = root->rchild = NULL;
        return;
    }
    while (t != NULL) {
        r = t;
        if (x < t->data) {
            t = t->lchild;
        } else if (x > t->data) {
            t = t->rchild;
        } else {
            return;
        }
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->lchild = p->rchild = NULL;

    if (x < r->data) {
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}

void preorder(struct Node *root) {
    if (root == NULL)
        return;
    printf("\t%d", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(struct Node *root) {
    if (root == NULL)
        return;
    inorder(root->lchild);
    printf("\t%d", root->data);
    inorder(root->rchild);
}

int main() {
    int ch, x;
    do {
        printf("\n\nEnter: \n\n\t1 -> Insert into the tree\n\t2 -> Preorder Traversal\n\t3 -> Inorder Traversal\n\t99 -> Exit");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n\n\tEnter the value to insert: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                printf("\n\n\tPreorder traversal:\n");
                preorder(root);
                break;
            case 3:
                printf("\n\n\tInorder traversal:\n");
                inorder(root);
                break;
            case 99:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
        }
    } while (ch != 99);
    return 0;
}
