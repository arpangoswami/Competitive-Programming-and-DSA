#include<bits/stdc++.h>
using namespace std;
bool check(int *arr,int n,int stu,int mid){
    int ct = 1,s = 0;
    int i = 0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(s>mid){
            s = arr[i];
            ct++;
        }
    }
    if(ct>stu) return false;
    return true;
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        int n,stu;
        cin>>n>>stu;
        int *arr = new int[n];
        int sum = 0;
        for(int i=0;i<n;i++){ 
            cin>>arr[i];
            sum+=arr[i];
        }
        if(stu>=n){
            cout<<arr[n-1]<<endl;
            continue;
        }
        int min_page = arr[n-1],max_page = sum,ans = max_page;
        while(min_page<=max_page){
            int mid = (min_page + max_page)/2;
            bool flag = check(arr,n,stu,mid);
            if(flag){
                ans = mid;
                max_page = mid - 1;
            }
            else{
                min_page = mid + 1;
            }
        }
        cout<<ans<<endl;
        delete []arr;
    }
    return 0;
}