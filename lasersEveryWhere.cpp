#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,q;
        cin>>n>>q;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        while(q--){
            int x1,x2,y;
            cin>>x1>>x2>>y;
            int ct = 0;
            for(int j = (x1-1) ; j<(x2-1) ; j++){
                if(y>arr[j] && y<arr[j+1]){
                    ct++;
                }
                else if(y<arr[j] && y>arr[j+1]) ct++;
                else if(y == arr[j+1]) ct++;
                else if(y == arr[j]) ct++;
            }
            cout<<ct<<endl;
        }
        delete []arr;
    }
}
