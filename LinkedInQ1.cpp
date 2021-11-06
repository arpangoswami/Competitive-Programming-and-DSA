#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<long> bitwiseEquations(vector<long> a,vector<long> x){
	int n = a.size();
	vector<long> sol(n);
	for(int i=0;i<n;i++){
		long ans = 0;
		bool flag = true;
		long Xor = x[i],sum = a[i];
		if(sum < Xor){
			continue;
		}
		long And = (sum - Xor)/2;
		for(int j=61;j>=0;j--){
			int bit1 = (Xor >> j) & 1,bit2 = (And >> j) & 1;
			if(bit1 && bit2){
				sol[i] = 0;
				flag = false;
				break;
			}else if(!bit1 && bit2){
				ans += (1LL << j);
			}
			if(!flag){
				break;
			}
		}
		if(flag){
			sol[i] = 2*ans + 3*(sum - ans);
		}
	}
	return sol;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<long> a(n),x(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	vector<long> ans = bitwiseEquations(a,x);
	for(long x:ans){
		cout<<x<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}