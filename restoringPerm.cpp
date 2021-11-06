#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	set<int> st1,st2;
	for(int i=1;i<=n;i++){
		st1.insert(i);
		st2.insert(i);
	}
	vector<int> rearrange(n);
	for(int &i:rearrange){
		cin >> i;
	}
	vector<int> maxm(n),minm(n);
	maxm[0] = rearrange[0];
	minm[0] = rearrange[0];
	st1.erase(maxm[0]);
	st2.erase(minm[0]);
	for(int i=1;i<n;i++){
		if(rearrange[i] == rearrange[i-1]){
			auto it = st1.begin();
			minm[i] = *it;
			st1.erase(it);
			it = st2.lower_bound(rearrange[i]);
			if(it != st2.begin()){
				it--;
			}
			maxm[i] = *it;
			st2.erase(it);
		}else{
			maxm[i] = rearrange[i];
			minm[i] = rearrange[i];
			st1.erase(maxm[i]);
			st2.erase(minm[i]);
		}
	}
	for(int i:minm){
		cout << i << " ";
	}
	cout << '\n';
	for(int i:maxm){
		cout << i << " ";
	}
	cout << '\n';
	
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