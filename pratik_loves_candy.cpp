#include <bits/stdc++.h>
#define int long long
using namespace std;
#define N 1000001
bitset<N> bs;
vector<int> primes;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	bs.set();
	bs[0] = 0;
	bs[1] = 0;
	primes.push_back(2);
	for(int i=4;i<N;i+=2){
		bs[i] = 0;
	}
	for(int i=3;i<N;i+=2){
		if(bs[i] == 1){
			primes.push_back(i);
			for(int j=i*i;j<N;j+=i){
				bs[j] = 0;
			}
		}
	}
	while(test--){
		int num;
		cin >> num;
		cout << primes[num-1] << "\n";
	}
	return 0;
}