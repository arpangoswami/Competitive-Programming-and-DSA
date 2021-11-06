#include<stdio.h>
#include<stdlib.h>
struct poly{
    float coeff;
    int expo;
    struct poly *link;
};
struct poly *create(struct poly *);
struct poly *insert_sorted(struct poly *,float,int);
struct poly *insert(struct poly *,float,int);
void poly_add(struct poly *p1,struct poly *p2);
void display(struct poly *p);
int main(void){
    struct poly *start1=NULL,*start2=NULL;
    printf("Enter first polynomial:\n");
    start1=create(start1);
    printf("Enter second polynomial:\n");
    start2=create(start2);
    printf("First polynomial is:\n");
    display(start1);
    printf("Second polynomial is:\n");
    display(start2);
    poly_add(start1,start2);
}
struct poly *create(struct poly* start){
    int i,n,ex;
    float co;
    printf("Enter number of terms:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter coefficient for term %d: ",i);
        scanf("%f",&co);
        printf("Enter exponent for term %d: ",i);
        scanf("%d",&ex);
        start=insert_sorted(start,co,ex);
    }
    return start;
}
struct poly *insert_sorted(struct poly *start,float co,int ex){
    struct poly *temp, *p;
    temp=(struct poly*)malloc(sizeof(struct poly));
    temp->coeff=co;
    temp->expo=ex;
    if(start==NULL || ex > start->expo){
        temp->link=start;
        start=temp;
    }
    else{
        p=start;
        while(p->link!=NULL && p->link->expo>=ex){
            p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
    }
    return start;
}
struct poly *insert(struct poly *start,float co,int ex){
    struct poly *temp,*p;
    temp=(struct poly*)malloc(sizeof(struct poly));
    temp->coeff=co;
    temp->expo=ex;
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
void display(struct poly *p){
    if(p == NULL){
        printf("Zero polynomial");
        return;
    }
    while(p!=NULL){
        printf("(%.2fx^%d)",p->coeff,p->expo);
        p=p->link;
        if(p!=NULL)
            {printf(" + ");}
        else
            {printf("\n");}
    }
}
void poly_add(struct poly *p1,struct poly *p2){
    struct poly *start3=NULL;
    while(p1!=NULL && p2!=NULL){
        if((p1->expo)>(p2->expo))
        {
            start3=insert(start3,p1->coeff,p1->expo);
            p1=p1->link;
        }
        else if((p2->expo) > (p1->expo)){
            start3=insert(start3,p2->coeff,p2->expo);
            p2=p2->link;
        }
        else if((p2->expo) == (p1->expo)){
            start3=insert(start3,(p2->coeff+p1->coeff),p1->expo);
            p1=p1->link;
            p2=p2->link;
        }
    }
    while(p1!=NULL){
        start3=insert(start3,p1->coeff,p1->expo);
        p1=p1->link;
    }
    while(p2!=NULL){
        start3=insert(start3,p2->coeff,p2->expo);
        p2=p2->link;
    }
    printf("Added polynomial is:\n");
    display(start3);
}
