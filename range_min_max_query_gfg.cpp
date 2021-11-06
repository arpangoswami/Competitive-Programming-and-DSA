#include<bits/stdc++.h>
using namespace std;
struct element{
  int mini;
  int maxi;
};
void buildTree(int *arr,element *tree,int start,int finish,int treeNode){
    if(start == finish){
        tree[treeNode].mini = arr[start];
        tree[treeNode].maxi = arr[start];
        return;
    }
    int mid = start + (finish-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode + 1);
    buildTree(arr,tree,mid+1,finish,2*treeNode + 2);
    tree[treeNode].mini = min(tree[2*treeNode+1].mini,tree[2*treeNode+2].mini);
    tree[treeNode].maxi = max(tree[2*treeNode+1].maxi,tree[2*treeNode+2].maxi);
}
void update(int *arr,element *tree,int start,int finish,int treeNode,int idx,int val){
    if(start == finish){
        arr[idx] = val;
        tree[treeNode].mini = val;
        tree[treeNode].maxi = val;
        return;
    }
    int mid = start + (finish-start)/2;
    if(idx>mid){
        update(arr,tree,mid+1,finish,2*treeNode+2,idx,val);
    }
    else{
        update(arr,tree,start,mid,2*treeNode+1,idx,val);
    }
    tree[treeNode].mini = min(tree[2*treeNode+1].mini,tree[2*treeNode+2].mini);
    tree[treeNode].maxi = max(tree[2*treeNode+1].maxi,tree[2*treeNode+2].maxi);
}
element query(element *tree,int treeNode,int start,int finish,int left,int right){
    if(start>right || finish<left){
        element e;
        e.maxi = INT_MIN;
        e.mini = INT_MAX;
        return e;
    }
    if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start + (finish-start)/2;
    element ans1 = query(tree,2*treeNode+1,start,mid,left,right);
    element ans2 = query(tree,2*treeNode+2,mid+1,finish,left,right);
    element e;
    e.mini = min(ans1.mini,ans2.mini);
    e.maxi = max(ans1.maxi,ans2.maxi);
    return e;
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        int n,q;
        cin>>n>>q;
        int *arr = new int[n]();
        element *tree = new element[4*n]();
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        buildTree(arr,tree,0,n-1,0);
        /*for(int i=0;i<2*n+2;i++){
            cout<<tree[i].mini<<" "<<tree[i].maxi<<endl;
        }*/
        while(q--){
            char c;
            cin>>c;
            if(c == 'G'){
                int left,right;
                cin>>left>>right;
                element ans = query(tree,0,0,n-1,left,right);
                cout<<ans.mini<<" "<<ans.maxi<<endl;
            }
            else{
                int idx,val;
                cin>>idx>>val;
                update(arr,tree,0,n-1,0,idx,val);
            }
        }
        delete []arr;
        delete []tree;
    }
    return 0;
}
