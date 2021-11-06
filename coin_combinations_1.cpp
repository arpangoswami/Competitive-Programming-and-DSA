#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
const ll mod = 1e9+7;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,sum;
	cin>>n>>sum;
	vector<int> coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	vector<ll> arr(sum+1,0);
	arr[0] = 1;
	for(int i=1;i<=sum;i++){
		for(int j=0;j<n;j++){
			if(i >= coins[j]){
				arr[i]+=arr[i - coins[j]];
				arr[i]%=mod;
			}
		}
	}
	cout<<arr[sum]<<endl;
	return 0;
}