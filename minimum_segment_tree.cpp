#include<bits/stdc++.h>
using namespace std;
void buildTree(int *arr,int *tree,int start,int finish,int treeNode){
    if(start==finish){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+finish)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,finish,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
int query(int *tree,int start,int finish,int treeNode,int left,int right){
    if(start>right || finish<left){
            return INT_MAX;
    }
    else if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid=(start+finish)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,finish,2*treeNode+1,left,right);
    return min(ans1,ans2);
}
void updateTree(int *arr,int *tree,int start,int finish,int treeNode,int index,int value){
    if(start==finish){
        arr[index]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=(start+finish)/2;
    if(index>mid){
        updateTree(arr,tree,mid+1,finish,2*treeNode+1,index,value);
    }
    else{
        updateTree(arr,tree,start,mid,2*treeNode,index,value);
    }
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
int main(void){
    int n,q;
    cin>>n>>q;
    int *arr=new int[n];
    int *tree=new int[4*n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(arr,tree,0,n-1,1);
    /*for(int i=1;i<10;i++){
        cout<<tree[i]<<" ";
    }*/
    //cout<<query(tree,0,4,1,2,4)<<endl;
    while(q--){
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='q'){
            int m=query(tree,0,n-1,1,a-1,b-1);
            cout<<m<<endl;
        }
        else if(c=='u'){
            updateTree(arr,tree,0,n-1,1,a-1,b);
        }
    }
    delete []arr;
    delete []tree;
}
