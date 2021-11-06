#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *link;
};
struct node *newnode(int info){
    struct node *NewNode = (struct node *)malloc(sizeof(struct node));
    NewNode ->data = info;
    NewNode->
}
