#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        set<int> ar;
        for(int i=0;i<n;i++){
            ar.insert(arr[i]);
        }
        int siz = ar.size();
        vector<int> arr1;
        vector<bool> arr2;
        vector<int> arr3;
        for(auto it = ar.begin();it!=ar.end();it++){
            arr1.push_back(*it);
            arr2.push_back(false);
        }
        for(int i=0;i<m;i++)
        int greatest = m;
        for(int i=m;i>=1;i--){
            if(arr2[i-1] == true)
            bool flag = true;
            for(int j=arr1.size();j>=0;j--){
                if(__gcd(i,arr1[j])!=1){
                    flag = false;
                    greatest =
                    break;
                }
            }
        }
    }
}
