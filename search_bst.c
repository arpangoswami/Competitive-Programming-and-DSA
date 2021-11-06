#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    struct node *right;
    int info;
};
struct node *search(struct node *ptr, int skey){
    if(ptr==NULL){
        printf("Search was unsuccessful\n");
        return NULL;
    }
    else if(skey<ptr->info){
        return search(ptr->left,skey);
    }
    else if(skey>ptr->info){
        return search(ptr->right,skey);
    }
    else{
        printf("Search was successful\n");
        return ptr;
    }
}
struct node *insert(struct node *ptr,int ikey){
    if(ptr == NULL){
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if(ikey < ptr->info){
        ptr->left = insert(ptr->left,ikey);
    }
    else if(ikey > ptr->info){
        ptr->right = insert(ptr->right,ikey);
    }
    else{
        printf("Duplicate Key\n");
        return ptr;
    }
}
struct node *del(struct node *ptr,int dkey){
    struct node *temp,*succ;
    if(ptr==NULL){
        printf("Key to be deleted not found.\n");
        return ptr;
    }
    if(dkey < ptr->info){
        ptr->left = del(ptr->left,dkey);
    }
    else if(dkey > ptr->info){
        ptr->right = del(ptr->right,dkey);
    }
    else{
        if(ptr->left!=NULL && ptr->right!=NULL){
            succ = ptr->right;
            while(succ->left){
                succ = succ->left;
            }
            ptr->info = succ->info;
            ptr->right = del(ptr->right,succ->info);
        }
        else{
            temp = ptr;
            if(ptr->left){
                ptr = ptr->left;
            }
            else if(ptr->right){
                ptr = ptr->right;
            }
            else{
                ptr = NULL;
            }
            free(temp);
        }
    }
    return ptr;
}
void preorder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    printf("%d  ",ptr->info);
    preorder(ptr->left);
    preorder(ptr->right);
}

void inorder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    inorder(ptr->left);
    printf("%d  ",ptr->info);
    inorder(ptr->right);
}

void postorder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d  ",ptr->info);
}
int main(void){
    struct node *root = NULL, *ptr;
    int choice,k;
    while(1){
        printf("\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Pre-order Traversal\n");
        printf("5.In-order Traversal\n");
        printf("6.Postorder Traversal\n");
        printf("7.Quit\n");
        printf("Please enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the element to be inserted: \n");
            scanf("%d",&k);
            root = insert(root,k);
            break;
        case 2:
            printf("Enter the element to be deleted: \n");
            scanf("%d",&k);
            root = del(root,k);
            break;
        case 3:
            printf("Enter the element to be searched: \n");
            scanf("%d",&k);
            ptr = search(root,k);
            if(ptr == NULL){
                printf("Key not present. \n");
            }
            else{
                printf("Key present. \n");
            }
            break;
        case 4:
            printf("Preorder traversal of given BST is: \n");
            preorder(root);
            break;
        case 5:
            printf("Inorder traversal of given BST is: \n");
            inorder(root);
            break;
        case 6:
            printf("Postorder traversal of given BST is: \n");
            postorder(root);
            break;
        case 7:
            exit(1);
        default:
            printf("Wrong option\n");
        }
    }
}
