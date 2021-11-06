#include <bits/stdc++.h>
#define int long long
using namespace std;
int countMax(vector<int> &initial,vector<int> &preferred){
	int n = initial.size(),m = preferred.size();
	if(n == 0LL || m == 0LL){
		return 0LL;
	}
	set<int> pos(preferred.begin(),preferred.end());
	vector<int> suffix(n+1);
	for(int i=n-1;i>=0;i--){
		suffix[i] = suffix[i+1] + pos.count(initial[i]);
	}
	int ans = 0;
	int j = 0,right = 0;
	for(int left = 0;left < m;left++){
		while(j < n && initial[j] <= preferred[left] + j){
			j++;
		}
		while(right < m && preferred[right] - preferred[left] < j){
			right++;
		}
		ans = max(ans,right-left+suffix[j]);
	}
	return ans;
}
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<int> posA,negA,posB,negB;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		if(v < 0){
			negA.push_back(-v);
		}else{
			posA.push_back(v);
		}
	}
	reverse(negA.begin(),negA.end());
	for(int i=0;i<m;i++){
		int v;
		cin >> v;
		if(v < 0){
			negB.push_back(-v);
		}else{
			posB.push_back(v);
		}
	}
	reverse(negB.begin(),negB.end());
	cout<<countMax(posA,posB) + countMax(negA,negB)<<'\n';
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