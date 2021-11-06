#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr =new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int kadane_sum = 0,sum_till_now = 0,total_sum = 0;
        for(int i=0;i<n;i++){
            sum_till_now+=arr[i];
            sum_till_now = max(sum_till_now,0);
            kadane_sum = max(sum_till_now,kadane_sum);
        }
        for(int i=0;i<n;i++){
            total_sum+=arr[i];
            arr[i]*=(-1);
        }
        sum_till_now = 0;
        int kadane = 0;
        for(int i=0;i<n;i++){
            sum_till_now+=arr[i];
            sum_till_now = max(sum_till_now,0);
            kadane = max(sum_till_now,kadane);
        }
        cout<<max(kadane_sum,total_sum+kadane)<<endl;
        delete []arr;
    }
}
