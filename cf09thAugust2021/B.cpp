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
	int n,k;
	cin >> n >> k;
	vi arr(n);
	int def = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<int> temp = arr;
	sort(temp.begin(),temp.end());
	map<int,int> sortedIdx;
	for(int i=0;i<n;i++){
		sortedIdx[temp[i]] = i;
	}
	int cmp = 0;
	for(int i=0;i<n;){
		int idx = sortedIdx[arr[i]];
		cmp++;
		while(i < n && idx < n && temp[idx] == arr[i]){
			i++;
			idx++;
		}
	}
	if(cmp <= k){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
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