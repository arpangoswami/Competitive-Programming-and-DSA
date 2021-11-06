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

void printDepth(int n){
	for(int i=0;i<n;i++){
		cout<<"(";
	}
	for(int i=0;i<n;i++){
		cout<<")";
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	// printDepth(n);
	// cout<<"\n";
	for(int i=0;i<n;i++){
		printDepth(i+1);
		printDepth(n-i-1);
		cout<<"\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}