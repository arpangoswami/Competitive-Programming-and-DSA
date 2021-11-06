#include <bits/stdc++.h>
using namespace std;
struct element{
    int idx;
    int first;
    int second;
};
void buildTree(int *arr1,int *arr2,element *tree,int start,int finish,int treeNode){
    if(start == finish){
        element e;
        e.idx = start;
        e.first = arr1[start];
        e.second = arr2[start];
        tree[treeNode] = e;
        return;
    }
    int mid = start + (finish-start)/2;
    buildTree(arr1,arr2,tree,start,mid,2*treeNode+1);
    buildTree(arr1,arr2,tree,mid+1,finish,2*treeNode+2);
    element e1 = tree[2*treeNode+1];
    element e2 = tree[2*treeNode+2];
    element e3;
    if(e1.first>e2.first){
        e3 = e1;
    }
    else if(e1.first<e2.first){
        e3 = e2;
    }
    else if(e1.second<=e2.second){
        e3 = e1;
    }
    else if(e1.second>e2.second){
        e3 = e2;
    }
    tree[treeNode] = e3;
}
element query(element *tree,int treeNode,int start,int finish,int left,int right){
    if(start>right || finish<left){
        element e;
        e.first = INT_MIN;
        e.second = INT_MAX;
        return e;
    }
    if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start + (finish-start)/2;
    element e1 = query(tree,2*treeNode+1,start,mid,left,right);
    element e2 = query(tree,2*treeNode+2,mid+1,finish,left,right);
    element e3;
    if(e1.first>e2.first){
        e3 = e1;
    }
    else if(e1.first<e2.first){
        e3 = e2;
    }
    else if(e1.second<=e2.second){
        e3 = e1;
    }
    else if(e1.second>e2.second){
        e3 = e2;
    }
    return e3;
}
int main(int argc,char const* argv[]){
    int n;
    cin>>n;
    int *arr1 = new int[n](),*arr2 = new int[n]();
    element *tree = new element[4*n+1]();
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    int q;
    cin>>q;
    buildTree(arr1,arr2,tree,0,n-1,0);
    while(q--){
        int left,right;
        cin>>left>>right;
        element e = query(tree,0,0,n-1,left-1,right-1);
        cout<<e.idx+1<<endl;
    }
    delete []arr1;
    delete []arr2;
    delete []tree;
    return 0;
}
