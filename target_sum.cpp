#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    int target;
    cin>>target;
    sort(arr,arr+n);
    /*for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }*/
    for(int i=0;i<n-1;i++){
        auto itr = mp.find(target-arr[i]);
        if(itr!=mp.end()){
            if(itr->second>0)
            {
                mp[arr[i]]--;
                mp[target-arr[i]]--;
                cout<<arr[i]<<" and "<<target-arr[i]<<endl;
            }
        }
    }
    delete []arr;
	return 0;
}
