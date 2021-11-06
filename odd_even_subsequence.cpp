#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
bool check(int element,vector<int> &arr,int k,int canPick){
	int picked = 0;
	for(int i=0;i<arr.size();i++){
		if(!canPick){
			picked++;
			canPick^=1;
		}else{
			if(arr[i]<=element){
				picked++;
				canPick^=1;
			}
		}
	}
	return picked>=k;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	int maxi = INT_MIN;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		maxi = max(maxi,arr[i]);
	}
	int low = 1,high = maxi,ans = high;
	while(low<=high){
		int mid = low + (high - low)/2;
		if(check(mid,arr,k,0) || check(mid,arr,k,1)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}