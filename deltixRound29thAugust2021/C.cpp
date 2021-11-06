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
	int n;
	cin >> n;
	int currLevel = 0,left = 0,ans = 0;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	if(n % 2){
		n--;
		arr.pop_back();
	}
	map<int,int> levels;
	for(int i=0;i<n;i+=2){
		int add = min(arr[i],arr[i+1]);
		ans += add;
		//cout<<"here: "<<ans<<"\n";
		ans += levels[currLevel];
//cout<<"thr: "<<ans<<"\n";
		if(arr[i] < arr[i+1]){
			arr[i+1] -= arr[i];
			arr[i] = 0;
			int extra = min(arr[i+1],currLevel);
			arr[i+1] -= extra;
			ans += extra;
			currLevel -= extra;
		}
		currLevel += (arr[i] - arr[i+1]);
		if(currLevel >= 0){
			levels[currLevel]++;
		}
		currLevel = max(currLevel,0LL);	
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}