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
/*
9
2 3 3 4 6 4 4 6 8
*/
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int N;
	cin >> N;
	map<int,int> freq;
	for(int i=0;i<N;i++){
		int u;
		cin >> u;
		freq[u]++;
	}
	vpi arr;
	for(auto it:freq){
		arr.push_back({it.first*it.second,it.first});
	}
	if(arr.size() == 1){
		cout<<arr[0].ff<<"\n";
	}else{
		int prevVal = arr[0].ff,maxVal = max(arr[0].ff,arr[1].ff);
		for(int i=2;i<arr.size();i++){
			int temp = maxVal;
			maxVal = max(prevVal + arr[i].ff,maxVal);
			prevVal = temp;
		}
		cout << maxVal << "\n";
	}
	return 0;
}