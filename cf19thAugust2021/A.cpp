#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	vector<int> ans(31);
	for(int i=0;i<n;i++){
		for(int j=0;j<=30;j++){
			if((arr[i] >> j) & 1){
				ans[j]++;
			}
		}
	}
	int sum = 0;
	for(int i=0;i<=30;i++){
		if(ans[i] == n){
			sum += (1LL << i);
		}
	}
	cout << sum << "\n";
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