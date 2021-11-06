#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi arr;
	char prev = s[0];
	int len = 0;
	for(int i=0;i<n;i++){
		if(s[i] == prev){
			len++;
		}else{
			arr.push_back(len);
			len = 1;
			prev = s[i];
		}
	}
	arr.push_back(len);
	int ans = 0,repeatedIndex = 0;
	for(int i=0;i<arr.size();i++){
		ans++;
		repeatedIndex = max(i,repeatedIndex);
		//skip over any continuous segment which has been omitted as prefix
		if(repeatedIndex < arr.size() && arr[repeatedIndex] >= 2){
			arr[repeatedIndex]--;
			//subtract from this continuous segment
			continue;
		}else{
			while(repeatedIndex < arr.size() && arr[repeatedIndex] == 1){
				repeatedIndex++;
				//go to next continuous segment
			}
		}
		if(repeatedIndex == arr.size()){
			i++;
			//Now 1010101... or 0101010... remains
		}else{
			arr[repeatedIndex]--;
		}
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}