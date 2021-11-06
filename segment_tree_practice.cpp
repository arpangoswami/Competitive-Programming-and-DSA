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
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int query(int *tree,int start,int finish,int treeNode,int left,int right){
    if(start>right || finish<left){
        return 0;
    }
    else if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid=(start+finish)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,finish,2*treeNode+1,left,right);
    return ans1+ans2;
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
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int main(void){
    int arr[]={1,2,3,4,5};
    int *tree=new int[10];
    buildTree(arr,tree,0,4,1);
    updateTree(arr,tree,0,4,1,2,10);
    for(int i=1;i<10;i++){
        cout<<tree[i]<<" "<<endl;
    }
    cout<<"Sum of elements of 3rd to 5th index is "<<query(tree,0,4,1,2,4)<<endl;
    delete [] tree;
}
