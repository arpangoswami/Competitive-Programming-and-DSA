/*https://practice.geeksforgeeks.org/problems/range-gcd-queries/0/?track=PC-W9-ST&batchId=154
You are given an array of size N, and Q queries. Queries are of 2 types:
1.0 L R(range query)-->Need to print GCD of arr elements in range [L, R].
2.1 index value (point update)-->Need to update the arr[index] with value
Your task is to Print GCD of the arr elements for every Query of type 0.

Note: 0-based indexing is used.

Input:
The input line contains T, denoting the number of testcases. Each testcases contains two lines. The first line contains N(size of array),Q(number of queries) . The second line contains N elements of the array separated by space. After that Q lines follow which contain queries of 2 types 0 and 1 . 0 Queries contain values L, R . 1 Queries contain index, value.

Output:
For each testcase in new line, print the GCD for each query in the required range.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= Q <= 105
0 <= L, R, index <= N-1
1 <= arr[i], value <= 106

Example:
Input:
1
6 3
2 3 4 6 8 16
0 0 2
1 3 8
0 2 5

Output:
1
4

Explanation:
Testcase 1:
There are 3 queries:
Query 1 : gcd(2, 3, 4) = 1
Query 2 : 6 changes to 8
Query 3 : gcd(4, 8, 8, 16) = 4


** For More Input/Output Examples Use 'Expected Output' option **
Author: SIDG*/
#include<bits/stdc++.h>
using namespace std;
void buildTree(int *arr,int *tree,int start,int finish,int treeNode){
    if(start == finish){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = start + (finish-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode + 1);
    buildTree(arr,tree,mid+1,finish,2*treeNode + 2);
    tree[treeNode] = __gcd(tree[2*treeNode+1],tree[2*treeNode+2]);
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
    tree[treeNode] = __gcd(tree[2*treeNode+1],tree[2*treeNode+2]);
}
int query(int *tree,int treeNode,int start,int finish,int left,int right){
    if(start>right || finish<left){
        return 0;
    }
    if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start + (finish-start)/2;
    int ans1 = query(tree,2*treeNode+1,start,mid,left,right);
    int ans2 = query(tree,2*treeNode+2,mid+1,finish,left,right);
    return __gcd(ans1,ans2);
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        int n,q;
        cin>>n>>q;
        int *arr = new int[n]();
        int *tree = new int[4*n]();
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        buildTree(arr,tree,0,n-1,0);
        for(int i=0;i<2*n+3;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
        while(q--){
            int type;
            cin>>type;
            if(type == 0){
                int left,right;
                cin>>left>>right;
                int ans = query(tree,0,0,n-1,left,right);
                cout<<ans<<endl;
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

