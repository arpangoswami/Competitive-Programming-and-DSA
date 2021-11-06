#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> sieve;
vector<int> query;
void pre(){
	sieve.resize(1e6+1);
	query.resize(1e6+1);
	for(int i=0;i<=1e6;i++){
		sieve[i] = 1;
	}
	sieve[0] = 0;
	sieve[1] = 0;
	for(int i=4;i<=1e6;i+=2){
		sieve[i] = 0;
	}
	for(int i=3;i*i<=1e6;i++){
		if(sieve[i]){
			for(int j=i*i;j<=1e6;j+=i){
				sieve[j] = 0;
			}
		}
	}
	for(int i=0;i<=1e6;i++){
		query[i] = 0;
	}
	for(int i=5;i<=1e6;i++){
		query[i] = query[i-1];
		if(sieve[i] == sieve[i-2] && sieve[i]){
			query[i]++;
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	cout<<query[n]<<'\n';
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