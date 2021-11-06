#include <iostream>
#define INT_MAX 1e9
using namespace std;
struct element{
    int mini;
    int maxi;
};
void buildTree(int *arr,int *tree,int start,int finish,int treeNode){
    if(start == finish){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = start + (finish-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode + 1);
    buildTree(arr,tree,mid+1,finish,2*treeNode + 2);
    tree[treeNode] = min(tree[2*treeNode+1],tree[2*treeNode+2]);
}
void update(int *arr,int *tree,int start,int finish,int treeNode,int idx,int val){
    if(start == finish){
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    int mid = start + (finish-start)/2;
    if(idx>mid){
        update(arr,tree,mid+1,finish,2*treeNode+2,idx,val);
    }
    else{
        update(arr,tree,start,mid,2*treeNode+1,idx,val);
    }
    tree[treeNode] = min(tree[2*treeNode+1],tree[2*treeNode+2]);
}
int query(int *tree,int treeNode,int start,int finish,int left,int right){
    if(start>right || finish<left){
        return INT_MAX;
    }
    if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start + (finish-start)/2;
    int ans1 = query(tree,2*treeNode+1,start,mid,left,right);
    int ans2 = query(tree,2*treeNode+2,mid+1,finish,left,right);
    return min(ans1,ans2);
}
int main(int argc,char const* argv[]){
    int n,q;
    cin>>n>>q;
    int *arr = new int[n]();
    int *tree = new int[3*n]();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(arr,tree,0,n-1,0);
    while(q--){
        char c;
        cin>>c;
        if(c == 'q'){
            int left,right;
            cin>>left>>right;
            int ans = query(tree,0,0,n-1,left-1,right-1);
            cout<<ans<<endl;
        }
        else{
            int idx,val;
            cin>>idx>>val;
            update(arr,tree,0,n-1,0,idx-1,val);
        }
    }
    delete []arr;
    delete []tree;
    return 0;
}

