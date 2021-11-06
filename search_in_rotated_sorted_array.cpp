#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int toSearchIndex(vector<int> &arr,int search){
	int low = 0,high = arr.size()-1;
	while(low<=high){
		int mid = low + (high - low)/2;
		if(arr[mid] == search){
			return mid;
		}
		else if(arr[mid]<arr[high]){
			if(search>arr[mid] && search<=arr[high]){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		else{
			if(search>=arr[low] && search<arr[mid]){
				high = mid - 1;
			}
			else{
				low = mid+1;
			}
		}
	}
	return -1;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	int search;
	cin>>search;
	cout<<toSearchIndex(arr,search)<<"\n";
	return 0;
}