#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<ll> heights(n);
	vector<ll> spices(n);
	for(int i=0;i<n;i++){
		cin>>heights[i];
	}
	for(int i=0;i<n;i++){
		cin>>spices[i];
	}
	for(int i=0;i<q;i++){
		int type;
		ll x1,x2;
		cin>>type>>x1>>x2;
		if(type == 1){
			spices[x1-1] = x2;
		}else{
			int start = x1-1;
			int dest = x2-1;
			bool plus = true;
			if(dest > start){
				plus = false;
			}
			bool exists = true;
			ll ans = 0;
			ll maxm = 0;
			for(int i=dest;i!=start;){
				if(heights[start] <= heights[i]){
					exists = false;
					break;
				}
				if(heights[i] > maxm){
					maxm = heights[i]; 
					ans+=spices[i];
				}
				if(plus){
					i++;
				}else{
					i--;
				}
			}
			ans+=spices[start];
			ans = exists ? ans : -1;
			cout << ans << "\n";
		}
	}
	return 0;
}