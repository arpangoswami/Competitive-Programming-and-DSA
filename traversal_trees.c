#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode ->data = data;
    NewNode ->left = NULL;
    NewNode ->right = NULL;
    return NewNode;
}

void preorder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    printf("%d  ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}

void inorder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    inorder(ptr->left);
    printf("%d  ",ptr->data);
    inorder(ptr->right);
}

void postorder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d  ",ptr->data);
}
int main(void){
    struct node *root = newNode(50);
    root->left = newNode(40);
    root->right = newNode(60);
    root->left->left = newNode(30);
    root->left->left->left = newNode(25);
    root->left->left->left->left = newNode(20);
    root->left->left->right = newNode(35);
    root->left->left->right->left = newNode(33);
    root->left->left->right->right = newNode(36);
    root->right->right = newNode(70);
    root->right->right->left = newNode(65);
    root->right->right->right = newNode(80);
    printf("The preorder traversal looks like: \n");
    preorder(root);
    printf("\n");
    printf("The inorder traversal looks like: \n");
    inorder(root);
    printf("\n");
    printf("The postorder traversal looks like: \n");
    postorder(root);
    printf("\n");
}
