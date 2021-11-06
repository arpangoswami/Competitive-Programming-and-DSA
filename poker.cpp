#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf = 1e9+1;
int power(int x,int y){
	int ans = 1LL;
	while(y){
		if(y & 1){
			ans *= x;
		}
		x *= x;
		y>>=1;
	}
	return ans;
}
void solveQuestion(){
	int k;
	cin >> k;
	string s,t;
	cin >> s >> t;
	vector<int>freqA(10),freqB(10);
	for(int i=0;i<4;i++){
		freqA[s[i] - '0']++;
		freqB[t[i] - '0']++;
	}
	int num = 0;
	int den = 0;
	for(int i=1;i<=9;i++){
		if(freqA[i] + freqB[i] + 1 > k)
			continue;
		for(int j=1;j<=9;j++){
			if(freqA[j] + freqB[j] + 1 > k)
				continue;
			if(i == j && freqA[i] + freqB[i] + 2 > k)
				continue;
			freqA[i]++;
			freqB[j]++;
			int scoreA = 0,scoreB = 0;
			for(int l=1;l<=9;l++){
				scoreA += l * power(10,freqA[l]);
				scoreB += l * power(10,freqB[l]);
			}
			freqA[i]--;
			freqB[j]--;
			if(i == j){
				int rem = (k - freqA[i] - freqB[j]);
				if(scoreA > scoreB){
					num += (rem * (rem-1));
				}
				den += (rem * (rem-1));
			}else{
				int remA = (k - freqA[i] - freqB[i]),remB = (k - freqA[j] - freqB[j]);
				if(scoreA > scoreB){
					num += (remA * remB);
				}
				den += (remA * remB);
			}
		}
	}
			
	cout<<fixed<<setprecision(7)<<(double)(num)/(double)(den);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}