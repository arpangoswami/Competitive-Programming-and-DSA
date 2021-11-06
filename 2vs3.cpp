// 2 vs 3
// Attempted by: 1922/Accuracy: 39%/Maximum Score: 30/
//  77 Votes
// Tag(s): Easy-Medium, Mathematics, Modular arithmetic, Segment tree, Tree
// PROBLEM
// EDITORIAL
// MY SUBMISSIONS
// ANALYTICS
// The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.

// The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.

// Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.

// Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

// Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.

// The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.

// Input:

// The first line contains N denoting the length of the binary string .The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.This is followed up by Q lines where each line contains a query.

// Output:

// For each query of Type 0 print the value modulo 3.

// Constraints:

// 1<= N <=10^5

// 1<= Q <= 10^5

// 0 <= l <= r < N

// SAMPLE INPUT 
// 5
// 10010
// 6
// 0 2 4
// 0 2 3
// 1 1
// 0 0 4
// 1 1
// 0 0 3
// SAMPLE OUTPUT 
// 2
// 1
// 2
// 1
// Explanation
// Query 1 : This is of type 0. The binary string is 010 which is equal to 2 and 2%3=2. So answer is 2.

// Query 2 : This is of type 0. The binary string is 01 which is equal to 1 ( (2^1) * 0 +(2^0) * 1 ) =0 + 1 =1) and 1%3=1. So answer is 1.

// Query 3 : This is of type 1. The value at index 1 is 0 so we flip it .The new string is 11010.

// Query 4 : This is of type 0. The binary string is 11010 ( (2^0) * 0 +(2^1) * 1 +(2^2) * 0 +(2^3) * 1 +(2^4) * 1 = 2 + 8 +16 =26 ) which is equal to 26 and 26%3=2. So answer is 2.

// Query 5 : This is of type 1. The value at index 1 is 1 so we do nothing .The new string is 11010.

// Query 6 : This is of type 0. The binary string is 1101 ( (2^0) * 1 +(2^1) * 0 +(2^2) * 1 +(2^3) * 1 = 1 + 4+ 8 =13 ) which is equal to 13 and 13%3=1. So answer is 1.
#include<bits/stdc++.h>
using namespace std;
void buildTree(string &arr,int *tree,int low,int high,int i){
    if(low == high){
        if(arr[low] == '1'){
            tree[i] = 1;
        }
        else{
            tree[i] = 0;
        }
        return;
    }
    int mid = low + (high - low)/2;
    buildTree(arr,tree,low,mid,2*i+1);
    buildTree(arr,tree,mid+1,high,2*i+2);
    if((high - mid)%2 == 0)
        tree[i] = (tree[2*i+1] + tree[2*i+2])%3;
    else
        tree[i] = (tree[2*i+1]*2 + tree[2*i+2])%3;
}
void update(string &arr,int *tree,int low,int high,int i,int idx){
    if(low == high){
        tree[i] = 1;
        arr[low] = '1';
        return;
    }
    int mid = low + (high - low)/2;
    if(idx>mid){
        update(arr,tree,mid+1,high,2*i+2,idx);
    }
    else{
        update(arr,tree,low,mid,2*i+1,idx);
    }
    if((high - mid)%2 == 0)
        tree[i] = (tree[2*i+1] + tree[2*i+2])%3;
    else
        tree[i] = (tree[2*i+1]*2 + tree[2*i+2])%3;
}
int query(int *tree,int low,int high,int i,int left,int right){
    //No overlap
    if(low>right || high<left){
        return 0;
    }
    //Complete Overlap
    else if(low>=left && high<=right){
        if((right - high)%2 == 0){
            return tree[i]%3;
        }
        return (tree[i]*2)%3;
    }
    //Partial Overlap
    int mid = low + (high - low)/2;
    int a1 = query(tree,low,mid,2*i+1,left,right);
    int a2 = query(tree,mid+1,high,2*i+2,left,right);
    return (a1+a2)%3;
}
int main(int argc,char const* argv[]){
    int length;
    cin>>length;
    string binary;
    cin>>binary;
    int queries;
    cin>>queries;
    int *tree = new int[4*length]();
    buildTree(binary,tree,0,length-1,0);
    while(queries--){
        int qtype;
        cin>>qtype;
        if(qtype == 0){
            int left,right;
            cin>>left>>right;
            cout<<query(tree,0,length-1,0,left,right)<<endl;
        }
        else{
            int idx;
            cin>>idx;
            update(binary,tree,0,length-1,0,idx);
        }
    }
    delete []tree;
    return 0;
}