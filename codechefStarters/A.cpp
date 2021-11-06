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
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	int maxNeg = -1;
	for(int i=0;i<n;i++){
		if(arr[i] < 0){
			maxNeg = i;
		}else{
			break;
		}
	}
	maxNeg = min(maxNeg,k-1);
	int sum = 0;
	for(int i=0;i<=maxNeg;i++){
		sum -= arr[i];
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i] > 0){
			sum += arr[i];
		}else{
			break;
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