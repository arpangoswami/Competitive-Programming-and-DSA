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
	vector<ll> items(5);
	for(int i=0;i<5;i++){
		cin>>items[i];
	}
	ll sum = 0;
	vector<ll> prizes(5,0);
	for(int i=0;i<n;i++){
		sum+=arr[i];
		while(sum >= items[0]){
			auto it = prev(upper_bound(items.begin(),items.end(),sum));
			int x = it - items.begin();
			ll prod = sum/items[x];
			sum-=(prod * items[x]);
			prizes[x]+=prod;
		}
	}
	for(ll x:prizes){
		cout<<x<<" ";
	}
	cout<<"\n";
	cout<<sum;
	return 0;
}