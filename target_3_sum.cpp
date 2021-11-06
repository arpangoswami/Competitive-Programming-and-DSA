#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int target;
	cin>>target;
	sort(arr,arr+n);
	for(int i=0;i<n-2;i++){
		int left = i+1,right = n-1;
		while(left<right){
			if(target>arr[i]+arr[left]+arr[right]){
				left++;
			}
			else if(target<arr[i]+arr[left]+arr[right]){
				right--;
			}
			else{
				cout<<arr[i]<<", "<<arr[left]<<" and "<<arr[right]<<endl;
				left++;
			}
		}
	}
	delete []arr;
}
