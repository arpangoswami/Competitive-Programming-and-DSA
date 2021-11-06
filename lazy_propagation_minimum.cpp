#include<bits/stdc++.h>
using namespace std;
void buildTree(int *arr,int *tree,int start,int end,int treeNode){
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = start + (end-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode+1);
    buildTree(arr,tree,mid+1,end,2*treeNode+2);
    tree[treeNode] = min(tree[2*treeNode+1],tree[2*treeNode+2]);
}
void updateLazily(int *tree,int *lazy,int low,int high,int startR,int endR,int treeNode,int inc){
    if(low>high){
        return;
    }
    if(lazy[treeNode]!=0){
        tree[treeNode]+=lazy[treeNode];
        if(low!=high){
            lazy[2*treeNode+1]+=lazy[treeNode];
            lazy[2*treeNode+2]+=lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    if(startR>high || endR<low){ //No Overlap
        return;
    }
    if(startR<=low && high<=endR){ //Complete Overlap
        tree[treeNode]+=inc;
        if(low!=high){
            lazy[2*treeNode+1]+=inc;
            lazy[2*treeNode+2]+=inc;
        }
        return;
    }
    //Partial Overlap
    int mid = low + (high-low)/2;
    updateLazily(tree,lazy,low,mid,startR,endR,2*treeNode+1,inc);
    updateLazily(tree,lazy,mid+1,high,startR,endR,2*treeNode+2,inc);
    tree[treeNode] = min(tree[2*treeNode+1],tree[2*treeNode+2]);
}
int queryLazily(int *tree,int *lazy,int low,int high,int startRange,int endRange,int pos){
    if(low>high){
        return INT_MAX;
    }
    if(lazy[pos]!=0){
        tree[pos]+=lazy[pos];
        if(low!=high){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(low>endRange || high<startRange){
        return INT_MAX;
    }
    if(low>=startRange && high<=endRange){
        return tree[pos];
    }
    int mid = low + (high - low)/2;
    return min(queryLazily(tree,lazy,low,mid,startRange,endRange,2*pos+1),queryLazily(tree,lazy,mid+1,high,startRange,endRange,2*pos+2));
}
int main(int argc,char const* argv[]){
    int arr[] = {1, 3, -2, 4};
    int *tree = new int[12]();
    int *lazy = new int[12]();
    buildTree(arr,tree,0,3,0);
    updateLazily(tree,lazy,0,3,0,3,0,3);
    updateLazily(tree,lazy,0,3,0,1,0,2);
    // cout<<"Segment Tree: "<<endl;
    // for(int i=0;i<12;i++){
    //     cout<<tree[i]<<endl;
    // }
    // cout<<"Lazy Tree: "<<endl;
    // for(int i=0;i<12;i++){
    //     cout<<lazy[i]<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
        int left,right;
        cin>>left>>right;
        cout<<queryLazily(tree,lazy,0,3,left-1,right-1,0)<<endl;
    }
    delete []tree;
    delete []lazy;
    return 0;
}