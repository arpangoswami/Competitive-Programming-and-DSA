/*
https://www.spoj.com/problems/KGSS/
KGSS - Maximum Sum
#tree
You are given a sequence A[1], A[2], ..., A[N] ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.

U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.

This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.

Q x y, 1 ≤ x < y ≤ N.

You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.

Output
Output the maximum sum mentioned above, in a separate line, for each Query.

Example
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12

*/
#include <bits/stdc++.h>
using namespace std;
struct element{
    int first;
    int second;
};
void buildTree(int *arr,element *tree,int start,int finish,int treeNode){
    if(start == finish){
        tree[treeNode].first = arr[start];
        tree[treeNode].second = INT_MIN;
        return;
    }
    int mid = start+(finish-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode+1);
    buildTree(arr,tree,mid+1,finish,2*treeNode+2);
    tree[treeNode].first = max(tree[2*treeNode+1].first,tree[2*treeNode+2].first);
    tree[treeNode].second = max(min(tree[2*treeNode+1].first,tree[2*treeNode+2].first),max(tree[2*treeNode+1].second,tree[2*treeNode+2].second));
}
void update(int *arr,element *tree,int start,int finish,int treeNode,int idx,int val){
    if(start == finish){
        arr[idx] = val;
        tree[treeNode].first = val;
        tree[treeNode].second = INT_MIN;
        return;
    }
    int mid = start+(finish-start)/2;
    if(idx>mid){
        update(arr,tree,mid+1,finish,2*treeNode+2,idx,val);
    }
    else{
        update(arr,tree,start,mid,2*treeNode+1,idx,val);
    }
    tree[treeNode].first = max(tree[2*treeNode+1].first,tree[2*treeNode+2].first);
    tree[treeNode].second = max(min(tree[2*treeNode+1].first,tree[2*treeNode+2].first),max(tree[2*treeNode+1].second,tree[2*treeNode+2].second));
}
element query(element *tree,int treeNode,int start,int finish,int left,int right){
    if(start>right || finish<left){
        element temp;
        temp.first = INT_MIN;
        temp.second = INT_MIN;
        return temp;
    }
    if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start+(finish-start)/2;
    element e1 = query(tree,2*treeNode+1,start,mid,left,right);
    element e2 = query(tree,2*treeNode+2,mid+1,finish,left,right);
    element e3;
    e3.first = max(e1.first,e2.first);
    e3.second = max(min(e1.first,e2.first),max(e1.second,e2.second));
    return e3;
}
int main(int argc,char const* argv[]){
    int n;
    cin>>n;
    int *arr = new int[n]();
    element *tree = new element[4*n+1]();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    buildTree(arr,tree,0,n-1,0);
    while(q--){
        char c;
        cin>>c;
        if(c == 'Q'){
            int left,right;
            cin>>left>>right;
            element e = query(tree,0,0,n-1,left-1,right-1);
            cout<<e.first+e.second<<endl;
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
