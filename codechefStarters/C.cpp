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
	int ans = 0;
	//1 must remain same
	//2 has been flipped 
	//0 can change state
	int n;
	cin >> n;
	vi arr1(n);
	for(int &i:arr1){
		cin >> i;
	}
	vi arr2(n);
	for(int &i:arr2){
		cin >> i;
	}
	vi state(n);
	for(int i=29;i>=0;i--){
		vector<int> flipped;
		vector<int> straight;
		int picked = 0;
		bool f = true;
		for(int j=0;j<n && f;j++){
			if(state[j] == 1 && ((arr1[j] >> i) & 1)){
				picked++;
			}else if(state[j] == 1 && !((arr1[j] >> i) & 1)){
				f = false;
			}else if(state[j] == 2 && ((arr2[j] >> i) & 1)){
				picked++;
			}else if(state[j] == 2 && !((arr2[j] >> i) & 1)){
				f = false;
			}else if(state[j] == 0){
				if(((arr1[j] >> i) & 1) && ((arr2[j] >> i) & 1)){
					picked++;
				}else if(((arr1[j] >> i) & 1) && !((arr2[j] >> i) & 1)){
					picked++;
					straight.push_back(j);
				}else if(!((arr1[j] >> i) & 1) && ((arr2[j] >> i) & 1)){
					picked++;
					flipped.push_back(j);
				}else{
					f = false;
				}
			}
		}
		if(picked == n){
			ans += (1 << i);
			for(int x:flipped){
				state[x] = 2;
			}
			for(int x:straight){
				state[x] = 1;
			}
		}
	}
	int cnt = count(state.begin(),state.end(),2);
	cout << ans << " " << cnt << "\n";
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