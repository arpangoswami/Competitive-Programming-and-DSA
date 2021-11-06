#include<iostream>
#include<vector>
using namespace std;
vector<int> allIndices(int *arr,int n,int val,int i,vector<int> &indices){
    if(arr[0] == val){
        indices.push_back(i);
    }
    if(n==0) return indices;
    return allIndices(arr+1,n-1,val,i+1,indices);
}
int main() {
    int n;
    cin>>n;
    vector<int> nums;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int value;
    cin>>value;
    nums = allIndices(arr,n,value,0,nums);
    for(int x = 0;x<nums.size();x++){
        cout<<nums[x]<<" ";
    }
	return 0;
}
