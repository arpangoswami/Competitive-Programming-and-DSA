#include<stdio.h>
#include<stdlib.h>
struct stack_node{
    int info;
    struct stack_node *link;
}*top = NULL;
struct queue_node{
    int data;
    struct queue_node *next;
}*front = NULL,*rear = NULL;
int isStackEmpty{
    if(top==NULL)
        return 1;
    return 0;
}
void stack_push(int item){
    struct stack_node *tmp=(struct stack_node*)malloc(sizeof(struct stack_node));
    if(!tmp){
        printf("Stack Overflow\n");
        return;
    }
    tmp->info=item;
    tmp->link=top;
    top=tmp;
}
int stack_pop(){
    struct stack_node *tmp;
    int item;
    if(isStackEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    tmp=top;
    item = top->info;
    top=top->link;
    free(tmp);
    return item;
}
void stack_display(){
    struct stack_node *ptr = top;
    if(isStackEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    printf("Stack Elements are:\n");
    while(ptr){
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
void queue_insert(int item){
    struct queue_node *tmp = (struct queue_node*)malloc(sizeof(struct queue_node));
    tmp->data = item;
}
int main(void){


}
