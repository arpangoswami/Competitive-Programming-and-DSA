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
	int n,k;
	cin >> n >> k;
	if(k > (n-1)/2){
		cout<<-1<<'\n';
		return;
	}
	vi arr(n);
	set<int> st;
	for(int i=1;i<=n;i++){
		st.insert(i);
	}
	int cnt = 0,num = n;
	for(int i=1;i<n && cnt<k;i+=2){
		arr[i] = num--;
		cnt++;
		st.erase(arr[i]);
		//last = i;
	}
	
	for(int i=0;i<n;i++){
		if(!arr[i]){
			arr[i] = *(st.begin());
			st.erase(arr[i]);
		}
	}
	for(int x:arr){
		cout<<x<<" ";
	}
	cout<<'\n';
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