#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *lchild,*rchild;
};

struct Node *root=NULL;

void insert(int x){
    struct Node *t=root,*p,*r;
    if(t==NULL){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        root=t;
        return;
    }
    while(t!=NULL){
        r=t;
        if(x<t->data){
            t=t->lchild;
        }else if(x>t->data){
            t=t->rchild;
        }else{
            return;
        }
    }

    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=x;
    p->lchild=p->rchild=NULL;
    if(x<r->data)
        r->lchild=p;
    else 
        r->rchild=p;
}


struct Node* rInsert(struct Node* root,int x){
    if(root==NULL){
        root=(struct Node*)malloc(sizeof(struct Node));
        root->data=x;
        root->lchild=root->rchild=NULL;
        return root;
    }else if(x<root->data){
        root->lchild=rInsert(root->lchild,x);
    }else if(x>root->data){
        root->rchild=rInsert(root->rchild,x);
    }else{
        printf("\n\n\t\tDuplicate value not allowed.");
        return root;
    }
    return root;
}

void preorder(struct Node *root){
    if(root==NULL)
        return;
    printf("\t%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(struct Node *root){
    if(root==NULL)
        return;
    inorder(root->lchild);
    printf("\t%d",root->data);
    inorder(root->rchild);
}

void postorder(struct Node *root){
    if(root==NULL)  return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("\t%d",root->data);
}

struct Node* rSearch(struct Node* root,int val){
    if(root==NULL){
        printf("\n\n\t\tElement is not present in the element");
        return root;
    }else if(val<root->data){
        return rSearch(root->lchild,val);
    }else if(root->data==val){
        printf("The element is present in the root");
        return root;
    }else{
        return rSearch(root->rchild,val);
    }
}

struct Node* iSearch(struct Node* root,int val){
    while(root!=NULL){
        if(root->data==val){
            printf("\n\n\t\t\tThe element is present in the tree");
            return root;
        }else if(val <root->data){
            root=root->lchild;
        }else{
            root=root->rchild;
        }
    }
    printf("\n\n\t\t\t\tThe Node is not present in the tree");
    return NULL;
}

int max(int x,int y){
    return x>y?x:y;
}

int height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->lchild),height(root->rchild))+1;
}

int inorderPre(struct Node* root){
    if(root->rchild==NULL)    return root->data;
    return inorderPre(root->rchild);
}

int inorderSuc(struct Node* root){
    if(root->lchild==NULL)  return root->data;
    return inorderSuc(root->lchild);
}

struct Node* deleteNode(struct Node* root,int x){
    if(x<root->data){
        root->lchild=deleteNode(root->lchild,x);
    }else if(x>root->data){
        root->rchild=deleteNode(root->rchild,x);
    }else{

        //Deleting the node if it's leaf node.
        if(root->lchild==NULL && root->rchild==NULL){
            delete root;
            return NULL;
        }else if(root->lchild!=NULL ^ root->rchild!=NULL){
            struct Node *temp=root->lchild==NULL?root->rchild:root->lchild;
            delete root;
            return temp;
        }else{
            if(height(root->lchild)>height(root->rchild)){
                int inPre=inorderPre(root->lchild);
                root->data=inPre;
                root->lchild=deleteNode(root->lchild,inPre);
            }else{
                int inSuc=inorderSuc(root->rchild);
                root->data=inSuc;
                root->rchild=deleteNode(root->rchild,inSuc);
            }
        }
    }
    return root;
}

int main(){
    int ch,x;
    root=rInsert(root,24);
    rInsert(root,12);
    rInsert(root,35);
    rInsert(root,6);
    rInsert(root,16);
    rInsert(root,40);
    do{
        printf("\n\nEnter : \n\n\t\t1 --------> for creating the tree.\n\n\t\t2  --------> for traversing the preorder. \n\n\t\t 3 --------> for traversing inorder.\n\n\t\t4 --------> fro traversing postorder.\n\n\t\t5 --------> for searching the element.\n\n\t\t6 --------> for deleting the element.");
        printf("\n\n\t\t\tEnter the choices :") ;
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("\n\n\t\tEnter the value to be insert inside the root : ");
                scanf("%d",&x);
                // bst->setRoot(bst->RecCreateTree(bst->getRoot(),x));/
                rInsert(root,x);
                break;
            case 2:
                printf("\n\n\n\t\tThe inorder traversal of the tree is\n\n\t\t\t:");
                inorder(root);
                break;
            case 3:
                printf("\n\n\n\t\tThe preorder traversal of the tree is\n\n\t\t\t:");
                preorder(root);
                break;
            case 4:
                printf("\n\n\n\t\tThe preorder traversal of the tree is\n\n\t\t\t:");
                postorder(root);
                break;
            case 5:
                printf("\n\n\t\tEnter the value to be searched inside the tree : ");
                scanf("%d",&x);
                // rSearch(root,x);
                iSearch(root,x);
                break;
            case 6:
                printf("\n\n\t\tEnter the value to be deleted inside the tree : ");
                scanf("%d",&x);
                // rSearch(root,x);
                root=deleteNode(root,x);
            case 99:
                printf("\n\n\t\tExiting the program.");
                break;
            default : 
                printf("\n\n\t\t\t______________Enter valid choice._____________");

        }
    }while(ch!=99);
    return 0;
}