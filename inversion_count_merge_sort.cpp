/*INVCNT - Inversion Count
#graph-theory #number-theory #shortest-path #sorting #bitmasks
Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2
5
Different question slightly different approach-
url - https://leetcode.com/problems/global-and-local-inversions/
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size() ;
        int pref[n] ;
        for(int i = 0 ; i < n ; ++i){
            pref[i] = 2e9;
        }
        pref[n-1] = A[n-1] ;
        for(int i = n - 2 ; i >= 0 ; --i){
            pref[i] = min(A[i] , pref[i+1]) ;
        }
        for(int i = n - 3 ; i>= 0 ; --i){
            if(A[i] > pref[i+2]) return false;
        }
        return true ;
    }
};

*/
#include<bits/stdc++.h>
using namespace std;
long long mergeOp(int *arr,int low,int mid,int up){
    long long coun = 0;
    int i=low,j=mid,k=0;
    int *arr1 = new int[up-low+1];
    while(i<mid && j<(up+1)){
        if(arr[i]<=arr[j]){
            arr1[k++] = arr[i++];
        }
        else{
            arr1[k++] = arr[j++];
            coun+=mid-i;
        }
    }
    while(i<mid){
        arr1[k++] = arr[i++];
    }
    while(j<=up){
        arr1[k++] = arr[j++];
    }
    for(int x=low,k=0;x<=up;x++,k++){
        arr[x] = arr1[k];
    }
    delete []arr1;
    return coun;
}
long long mergeSort(int *arr,int low,int up){

    if(low>=up) return 0;
    int mid = low+((up-low)/2);
    long long coun1 = mergeSort(arr,low,mid);
    long long coun2 = mergeSort(arr,mid+1,up);
    long long coun3 = mergeOp(arr,low,mid+1,up);
    return (coun1+coun2+coun3);
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long coun = mergeSort(arr,0,n-1);
        cout<<coun<<endl;
    }
}
