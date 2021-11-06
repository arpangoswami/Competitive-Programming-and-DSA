#include<bits/stdc++.h>
using namespace std;
int*reverseInGroups (int*mv, int n, int k){
    // your code here
    for(int i=0;i<n;i+=k){
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right){
            int temp = mv[left];
            mv[left] = mv[right];
            mv[right] = temp;
            left++;
            right--;
        }
    }
    return mv;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        arr = reverseInGroups(arr,n,k);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        delete []arr;
    }
}

