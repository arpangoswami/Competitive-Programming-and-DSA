#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	int cnt = 0;
	ll cm_sm = 0;
	for(int i=0;i<n;i++){
		if(arr[i] < cm_sm){
			cnt++;
		}else{
			cm_sm+=arr[i];
		}
	}
	cout<<n - cnt<<endl;
	return 0;
}