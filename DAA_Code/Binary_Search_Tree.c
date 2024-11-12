#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *NewNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root, int data){
    if (root == NULL){
        return NewNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}


void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct node *root = NULL;
    root = insert(root, 100);
    root = insert(root, 80);
    root = insert(root, 120);
    root = insert(root, 60);
    root = insert(root, 90);
    root = insert(root, 110);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}