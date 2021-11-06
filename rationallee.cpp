#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		vector<ll> gifts(n);
		vector<ll> require(k);
		for(int i=0;i<n;i++){
			cin>>gifts[i];
		}
		for(int i=0;i<k;i++){
			cin>>require[i];
		}
		vector<ll> maxi(k);
		vector<ll> mini(k);
		sort(gifts.begin(),gifts.end(),greater<int>());
		sort(require.begin(),require.end());
		int i;
		for(i=0;i<k && require[i] == 1;i++){
			maxi[i] = gifts[i];
			mini[i] = gifts[i];
		}
		int first = i;
		for(int j=first;j<k;j++){
			maxi[j] = gifts[j];
			require[j]--;
		}
		i = n-1;
		for(int j = k-1;j>=first;j--){
			mini[j] = gifts[i];
			i-=require[j];
		}
		ll sum = 0;
		for(int i=0;i<k;i++){
			sum+=maxi[i];
			sum+=mini[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}