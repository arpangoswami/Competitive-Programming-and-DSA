#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k,x;
	cin >> n >> k >> x;
	vector<int> freq(1024);
	for(int i=0;i<n;i++){
		int val = 0;
		cin >> val;
		freq[val]++;
	}
	vector<int> freq2(1024);
	for(int i=0;i<k;i++){
		for(int i=0;i<=1023;i++){
			freq2[i] = freq[i];
		}
		int pref = 0;
		for(int i=0;i<=1023;i++){
			if(freq[i] > 0){
				if(pref % 2 == 0){
					int xorVal = i ^ x;
					int sub = (freq[i] + 1)/2;
					freq2[i] -= sub;
					freq2[xorVal] += sub;
				}else{
					int xorVal = i ^ x;
					int sub = (freq[i])/2;
					freq2[i] -= sub;
					freq2[xorVal] += sub;
				}
				pref += freq[i];
			}
		}
		for(int i=0;i<=1023;i++){
			freq[i] = freq2[i];
		}
	}
	int maxm = 0,minm = 0;
	for(int i=1023;i>=0;i--){
		if(freq[i] > 0){
			maxm = i;
			break;
		}
	}
	for(int i=0;i<=1023;i++){
		if(freq[i] > 0){
			minm = i;
			break;
		}
	}
	cout<<maxm<<" "<<minm<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}