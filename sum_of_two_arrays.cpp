#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int n;
    cin>>n;
    vector<int> arr1(n,0);
    for(int i=n-1;i>=0;i--){
        int temp;
        cin>>temp;
        arr1[i] = temp;
    }
    int m;
    cin>>m;
    vector<int> arr2(m,0);
    for(int i = m-1;i>=0;i--){
        int temp;
        cin>>temp;
        arr2[i] = temp;
    }
    int ans_size = max(m+1,n+1);
    vector<int> ans_arr(ans_size,0);
    arr1.push_back(0);arr2.push_back(0);
    for(int i=0;i<ans_size-arr1.size();i++){
        arr1.push_back(0);
    }
    for(int i=0;i<ans_size-arr2.size();i++){
        arr2.push_back(0);
    }
    int carry = 0;
    for(int i=0;i<ans_size-1;i++){
        ans_arr[i] = (carry+arr1[i]+arr2[i])%10;
        carry = (carry+arr1[i]+arr2[i])/10;
    }
    if(carry){
        ans_arr[ans_size-1] = carry;
    }
    if(carry){
        cout<<ans_arr[ans_size-1]<<", ";
    }
    for(int i=ans_size-2;i>=0;i--){
        cout<<ans_arr[i]<<", ";
    }
    cout<<"END";
}
