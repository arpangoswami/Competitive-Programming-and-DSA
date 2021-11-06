#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N = 1e7+5;
int sieve[N];
int firstOcc[N];
void pre(){
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i){
			sieve[j] += i;
		}
	}
	for(int i=1;i<N;i++){
		if(sieve[i] < N && firstOcc[sieve[i]] == 0){
			firstOcc[sieve[i]] = i;
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	int ans = firstOcc[n];
	if(!ans){
		cout<<-1<<'\n';
		return;
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}