/*
https://www.spoj.com/problems/GSS1/
GSS1 - Can you answer these queries I
#tree
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.

Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one query per line.

Example
Input:
3
-1 2 3
1
1 2

Output:
2*/
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
        int left,right;
        cin>>left>>right;
        element e = query(tree,0,n-1,0,left-1,right-1);
        cout<<e.kadaneSum<<"\n";
    }
    delete []arr;
    delete []tree;
    return 0;
}
