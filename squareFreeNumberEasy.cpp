#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 1e7;
vector<int> primes;
int lowestPrime[N+1];
void pre() {
	for(int i=2;i<=N;i++){
		if(lowestPrime[i] == 0){
			//prime number itself
			lowestPrime[i] = i;
			primes.push_back(i);
		}
		for(int &x:primes){
			if(x > lowestPrime[i] || x * i > N){
				break;
			}
			lowestPrime[i * x] = x;
		}
	}
}
void solveQuestion() {
	int n,k;
	cin >> n >> k;
	vector<int> arr(n,1);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		while(x > 1){
			int cnt = 0;
			int p = lowestPrime[x];
			while(x % p == 0){
				cnt++;
				x/=p;
			}
			if(cnt & 1){
				arr[i] *= p;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;){
		set<int> st;
		int j = i;
		while(j < n && st.count(arr[j]) == 0){
			st.insert(arr[j]);
			j++;
		}
		i = j;
		ans++;
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	pre();
	while (test--) {
		solveQuestion();
	}
	return 0;
}