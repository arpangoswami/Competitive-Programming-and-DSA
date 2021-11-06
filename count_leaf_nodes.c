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
int getLeafNodes(struct node *Node){
    if(Node==NULL){
        return 0;
    }
    else if(Node->left==NULL && Node->right==NULL){
        return 1;
    }
    return getLeafNodes(Node->left)+getLeafNodes(Node->right);
}
int main(void)
{
    struct node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(1);
    printf("No. of leaf nodes are %d",getLeafNodes(root));
}
