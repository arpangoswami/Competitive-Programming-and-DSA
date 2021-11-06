#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int queue[SIZE];
int rear = -1;
int front = -1;
int isEmpty(){
    if(front == -1 || front == rear+1)
        return 1;
    return 0;
}
int isFull(){
    if(rear == 99){
        return 1;
    }
    return 0;
}
void push(int item){
    if(isFull()){
        printf("Queue Overflow.\n");
        return;
    }
    if(front == -1)
        front++;
    queue[++rear] = item;
}
int pop(){
    if(isEmpty()){
        printf("Queue underflow\n");
        exit(1);
    }
    return queue[front++];
}
void dfs_print(int adj_mat[][100],int n,int sv,int visited[]){
    printf("%d\t",sv);
    visited[sv]=1;
    for(int i=0;i<n;i++){
        /*if(i==sv){
            continue;
        }*/
        if(adj_mat[sv][i]==1){
            if(visited[i]){
                continue;
            }
            dfs_print(adj_mat,n,i,visited);
        }
    }
}
void print_bfs(int adj_mat[][100],int sv, int n){
    int visited[SIZE],current,i;
    for(i=0;i<n;i++){
            visited[i]=0;
        }
    push(sv);
    visited[sv]=1;
    while(isEmpty()!=1){
        current=pop();
        printf("%d\t",current);
        for(int i=0;i<n;i++){
            if(i == current)
                continue;
            if(adj_mat[current][i]==1 && !visited[i]){
                visited[i]=1;
                push(i);
            }
        }
    }
}
int main(void){
    int vertex,edges,adj_mat[SIZE][SIZE],p1,p2,visited[SIZE],i,j;
    printf("Enter number of vertices and edges respectively\n");
    scanf("%d%d",&vertex,&edges);
    for(i=0;i<vertex;i++){
        for(j=0;j<vertex;j++){
            adj_mat[i][j] = 0;
        }
    }
    while(edges--){
        printf("Enter two vertices which share an edge\n");
        scanf("%d%d",&p1,&p2);
        adj_mat[p1][p2]=1;
        adj_mat[p2][p1]=1;
    }
    for(i=0;i<vertex;i++){
        visited[i]=0;
    }
    printf("The breadth first traversal of the input graph is\n");
    print_bfs(adj_mat,0,vertex);
    printf("\n");
    printf("The depth first traversal of the input graph is\n");
    dfs_print(adj_mat,vertex,0,visited);
    printf("\n");
}
