/*
2
5
4
2 3 5 1 5
5
3
7 8 2 3 1
*/
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<vector<int>> groups(k);
	for(int i=0;i<k;i++){
		for(int j=i;j<n;j+=k){
			groups[i].push_back(arr[j]);
		}
	}
	vector<vector<int>> pref(k);
	for(int i=0;i<k;i++){
		pref[i].resize(groups[i].size());
		int N = pref[i].size();
		for(int j=1;j<N;j++){
			pref[i][j] = pref[i][j-1] + groups[i][j-1];
		}
	}
	int sum = 0;
	for(int i=0;i<k;i++){
		int N = pref[i].size();
		for(int j=1;j<N;j++){
			sum += (groups[i][j] * pref[i][j]);
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