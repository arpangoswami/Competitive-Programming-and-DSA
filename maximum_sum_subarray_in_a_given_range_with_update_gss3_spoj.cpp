/*
https://www.spoj.com/problems/GSS3/
GSS3 - Can you answer these queries III
#tree
You are given a sequence A of N (N <= 50000) integers between -10000 and 10000. On this sequence you have to apply M (M <= 50000) operations:
modify the i-th element in the sequence or for given x y print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }.

Input
The first line of input contains an integer N. The following line contains N integers, representing the sequence A1..AN.
The third line contains an integer M. The next M lines contain the operations in following form:
0 x y: modify Ax into y (|y|<=10000).
1 x y: print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }.
Output
For each query, print an integer as the problem required.

Example
Input:
4
1 2 3 4
4
1 1 3
0 3 -3
1 2 4
1 3 3

Output:
6
4
-3*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct element{
    ll sum;
    ll bestPrefixSum;
    ll bestSuffixSum;
    ll kadaneSum;
};
void buildTree(ll *arr,element *tree,int start,int finish,int treeNode){
    if(start == finish){
        element e;
        e.sum = arr[start];
        e.bestPrefixSum = arr[start];
        e.bestSuffixSum = arr[start];
        e.kadaneSum = arr[start];
        tree[treeNode] = e;
        return;
    }
    int mid = start + (finish-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode+1);
    buildTree(arr,tree,mid+1,finish,2*treeNode+2);
    element e1 = tree[2*treeNode+1],e2 = tree[2*treeNode+2];
    element e3;
    e3.sum = e1.sum+e2.sum;
    e3.bestPrefixSum = max(e1.sum+e2.bestPrefixSum,e1.bestPrefixSum);
    e3.bestSuffixSum = max(e2.bestSuffixSum,e2.sum+e1.bestSuffixSum);
    e3.kadaneSum = max(e1.kadaneSum,max(e2.kadaneSum,max(e1.sum+e2.bestPrefixSum,max(e1.bestSuffixSum+e2.bestPrefixSum,e1.bestSuffixSum+e2.sum))));
    tree[treeNode] = e3;
}
void update(ll *arr,element *tree,int start,int finish,int treeNode,int idx,int val){
    if(start == finish){
        arr[idx] = val;
        element e;
        e.sum = val;
        e.bestPrefixSum = val;
        e.bestSuffixSum = val;
        e.kadaneSum = val;
        tree[treeNode] = e;
        return;
    }
    int mid = start + (finish-start)/2;
    if(idx>mid){
        update(arr,tree,mid+1,finish,2*treeNode+2,idx,val);
    }
    else{
        update(arr,tree,start,mid,2*treeNode+1,idx,val);
    }
    element e1 = tree[2*treeNode+1],e2 = tree[2*treeNode+2];
    element e3;
    e3.sum = e1.sum+e2.sum;
    e3.bestPrefixSum = max(e1.sum+e2.bestPrefixSum,e1.bestPrefixSum);
    e3.bestSuffixSum = max(e2.bestSuffixSum,e2.sum+e1.bestSuffixSum);
    e3.kadaneSum = max(e1.kadaneSum,max(e2.kadaneSum,max(e1.sum+e2.bestPrefixSum,max(e1.bestSuffixSum+e2.bestPrefixSum,e1.bestSuffixSum+e2.sum))));
    tree[treeNode] = e3;
}
element query(element *tree,int start,int finish,int treeNode,int left,int right){
    if(start>right || finish<left){
        element e;
        e.sum = INT_MIN;
        e.bestPrefixSum = INT_MIN;
        e.bestSuffixSum = INT_MIN;
        e.kadaneSum = INT_MIN;
        return e;
    }
    else if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start + (finish-start)/2;
    element e1 = query(tree,start,mid,2*treeNode+1,left,right);
    element e2 = query(tree,mid+1,finish,2*treeNode+2,left,right);
    element e3;
    e3.sum = e1.sum+e2.sum;
    e3.bestPrefixSum = max(e1.sum+e2.bestPrefixSum,e1.bestPrefixSum);
    e3.bestSuffixSum = max(e2.bestSuffixSum,e2.sum+e1.bestSuffixSum);
    e3.kadaneSum = max(e1.kadaneSum,max(e2.kadaneSum,max(e1.sum+e2.bestPrefixSum,max(e1.bestSuffixSum+e2.bestPrefixSum,e1.bestSuffixSum+e2.sum))));
    return e3;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    ll *arr = new ll[n]();
    element *tree = new element[4*n+1]();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    buildTree(arr,tree,0,n-1,0);
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int left,right;
            cin>>left>>right;
            element e = query(tree,0,n-1,0,left-1,right-1);
            cout<<e.kadaneSum<<"\n";
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
