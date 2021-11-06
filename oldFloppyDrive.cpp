#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int timeRequired(int req,map<int,int> &mp){
	auto it = mp.lower_bound(req);
	return (it->second);
}
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vi arr(n);
	vi queries(m);
	for(int &i:arr){
		cin >> i;
	}
	for(int &i:queries){
		cin >> i;
	}
	int maxPrefSum = 0,currSum = 0,totalSum = 0;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		currSum += arr[i];
		if(currSum > maxPrefSum){
			mp[currSum] = i;
			maxPrefSum = currSum;
		}
	}
	totalSum = currSum;
	for(int x:queries){
		if(x > maxPrefSum && totalSum <= 0){
			cout<<-1<<" ";
			continue;
		}
		if(x <= maxPrefSum){
			cout<<timeRequired(x,mp)<<" ";
		}else{
			int val = (x - maxPrefSum);
			int rounds = (val + (totalSum-1))/totalSum;
			cout<<rounds*n + timeRequired(x-rounds*totalSum,mp)<<" ";
		}
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