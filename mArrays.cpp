#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vi arr(n);
	map<int,int> mod;
	for(int &i:arr){
		cin >> i;
		mod[i % m]++;
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		if(mod[i] == 0){
			continue;
		}
		if(i == 0){
			ans++;
			mod[i] = 0;
		}
		else if(m % 2 == 0 && i == m/2){
			ans++;
			mod[i] = 0;
		}else{
			int freq = mod[i],freqC = mod[m-i];
			if(freq == freqC){
				ans++;
				mod[i] -= freq;
				mod[m-i] -= freqC;
			}else{
				if(freq > freqC){
					mod[m-i] -= freqC;
					mod[i] -= freqC+1;
					ans++;
					ans += mod[i];
					mod[i] = 0;
				}else{
					mod[i] -= freq;
					mod[m-i] -= freq + 1;
					ans++;
					ans += mod[m-i];
					mod[m-i] = 0;
				}
			}
		}
	}
	cout << ans << '\n';
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