#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	map<int,int> mp;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
		mp[i]++;
	}
	vi sol(n);
	int ptr = 0;
	for(int i=0;i<n;i++){
		int req = i;
		if(mp.count(req) && mp[req] > 0){
			mp[req]--;
			sol[ptr++] = req;
			if(mp[req] == 0){
				mp.erase(req);
			}
		}else{
			break;
		}
	}
	for(auto it:mp){
		while(it.second > 0){
			sol[ptr++] = it.first;
			it.second--;
		}
	}
	for(int x:sol){
		cout<<x<<" ";
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}