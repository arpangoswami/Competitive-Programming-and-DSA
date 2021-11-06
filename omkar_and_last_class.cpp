#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> allFactors(int n){
	vi ans;
	ans.push_back(1);
	ans.push_back(n);
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			ans.push_back(i);
			ans.push_back(n/i);
		}
	}
	return ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		if(n%2 == 0){
			cout<<n/2<<" "<<n/2<<"\n";
		}else{
			vi factors = allFactors(n);
			sort(factors.begin(),factors.end());
			int maxL = n-1;
			int num = 1;
			for(int x:factors){
				if(((n-x) % x) == 0){
					if(maxL > max(x,n-x)){
						num = x;
						maxL = max(x,n-x);
					}
				}
			}
			cout<<num<<" "<<n-num<<"\n";
		}
	}
	return 0;
}