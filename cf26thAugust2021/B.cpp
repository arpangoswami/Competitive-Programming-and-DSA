#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
set<int> nonPrimes;
bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
void pre(){
	nonPrimes.insert(1);
	for(int i=2;i<=99;i++){
		if(!isPrime(i)){
			nonPrimes.insert(i);
		}
	}
}
void solveQuestion(){
	int N;
	cin >> N;
	string s;
	cin >> s;
	for(int i=0;i<N;i++){
		int num = s[i] - '0';
		if(nonPrimes.count(num)){
			cout<<"1\n";
			cout<<s[i]<<"\n";
			return;
		}
	}
	for(int i=0;i<(N-1);i++){
		for(int j=i+1;j<N;j++){
			int num = (s[i] - '0')*10 + s[j] - '0';
			if(nonPrimes.count(num)){
				cout<<"2\n";
				cout<<s[i]<<s[j]<<"\n";
				return;
			}
		}
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	pre();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}