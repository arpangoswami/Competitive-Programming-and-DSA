/*https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers.
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y.

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4*/
#include <bits/stdc++.h>
using namespace std;
struct element{
    int even;
    int odd;
};
void buildTree(int *arr,element *tree,int start,int finish,int treeNode){
    if(start == finish){
        if(arr[start]%2 == 0){
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;
        }
        else{
            tree[treeNode].even = 0;
            tree[treeNode].odd = 1;
        }
        return;
    }
    int mid = start + (finish-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode+1);
    buildTree(arr,tree,mid+1,finish,2*treeNode+2);
    tree[treeNode].even = tree[2*treeNode+1].even+tree[2*treeNode+2].even;
    tree[treeNode].odd = tree[2*treeNode+1].odd+tree[2*treeNode+2].odd;
}
element query(element *tree,int treeNode,int start,int finish,int left,int right){
    if(start>right || finish<left){
        element e;
        e.even = 0;
        e.odd = 0;
        return e;
    }
    if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start + (finish-start)/2;
    element e1 = query(tree,2*treeNode+1,start,mid,left,right);
    element e2 = query(tree,2*treeNode+2,mid+1,finish,left,right);
    element e3;
    e3.even = e1.even+e2.even;
    e3.odd = e1.odd+e2.odd;
    return e3;
}
void update(int *arr,element *tree,int start,int finish,int treeNode,int idx,int val){
    if(start == finish){
        arr[idx] = val;
        if(arr[start]%2 == 0){
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;
        }
        else{
            tree[treeNode].even = 0;
            tree[treeNode].odd = 1;
        }
        return;
    }
    int mid = start + (finish-start)/2;
    if(idx>mid){
        update(arr,tree,mid+1,finish,2*treeNode+2,idx,val);
    }
    else{
        update(arr,tree,start,mid,2*treeNode+1,idx,val);
    }
    tree[treeNode].even = tree[2*treeNode+1].even+tree[2*treeNode+2].even;
    tree[treeNode].odd = tree[2*treeNode+1].odd+tree[2*treeNode+2].odd;
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
        int type;
        cin>>type;
        if(type == 0){
            int idx,val;
            cin>>idx>>val;
            update(arr,tree,0,n-1,0,idx-1,val);
        }
        else if(type == 1){
            int left,right;
            cin>>left>>right;
            element e = query(tree,0,0,n-1,left-1,right-1);
            cout<<e.even<<endl;
        }
        else{
            int left,right;
            cin>>left>>right;
            element e = query(tree,0,0,n-1,left-1,right-1);
            cout<<e.odd<<endl;
        }
    }
    delete []arr;
    delete []tree;
    return 0;
}
