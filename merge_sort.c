#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *create(struct node *start);
struct node *insert_sorted(struct node *start,int data);
struct node *insert(struct node *start,int data);
void merge(struct node *p1,struct node *p2);
void display(struct node *start);
int main(void){
    struct node *start1=NULL,*start2=NULL;
    printf("Enter first list:\n");
    start1=create(start1);
    printf("Enter second list:\n");
    start2=create(start2);
    printf("First list in sorted order is:\n");
    display(start1);
    printf("Second list in sorted order is:\n");
    display(start2);
    merge(start1,start2);
}
struct node *create(struct node* start){
    int data,n,i;
    printf("Enter number of terms:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter data for term %d: ",i);
        scanf("%d",&data);
        start=insert_sorted(start,data);
    }
    return start;
}
struct node *insert(struct node *start,int data){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL){
        temp->link=start;
        start=temp;
    }
    else{
        p=start;
        while(p->link!=NULL)
            p=p->link;
        temp->link=p->link;
        p->link=temp;
    }
    return start;
}
void display(struct node *p){
    if(p == NULL){
        printf("No terms in the list");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->link;
        if(p==NULL)
            {printf("\n");}
    }
}

struct node *insert_sorted(struct node *start,int data){
    struct node *temp, *p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL || data < start->info){
        temp->link=start;
        start=temp;
    }
    else{
        p=start;
        while(p->link!=NULL && p->link->info<=data){
            p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
    }
    return start;
}
void merge(struct node *p1,struct node *p2){
    struct node *start3=NULL;
    while(p1!=NULL && p2!=NULL){
        if((p1->info)<(p2->info))
        {
            start3=insert(start3,p1->info);
            p1=p1->link;
        }
        else if((p2->info) < (p1->info)){
            start3=insert(start3,p2->info);
            p2=p2->link;
        }
        else if((p2->info) == (p1->info)){
            start3=insert(start3,p1->info);
            start3=insert(start3,p1->info);
            p1=p1->link;
            p2=p2->link;
        }
    }
    while(p1!=NULL){
        start3=insert(start3,p1->info);
        p1=p1->link;
    }
    while(p2!=NULL){
        start3=insert(start3,p2->info);
        p2=p2->link;
    }
    printf("Merged list is:\n");
    display(start3);
}
