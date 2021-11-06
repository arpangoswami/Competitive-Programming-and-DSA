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
	if(n == 2){
		cout<<-1<<'\n';
		return;
	}
	vector<vector<int>> ans(n,vector<int>(n));
	int ptr = 1;
	for(int i = 0;i<n && ptr <= (n*n);i++){
		for(int j = 0;j<n && ptr <= (n*n);j++){
			ans[i][j] = ptr;
			ptr += 2;
		}
	}
	ptr = 2;
	int row = -1,col = -1;
	bool found = false;
	for(int i=0;i<n && !found;i++){
		for(int j=0;j<n;j++){
			if(ans[i][j] == 0){
				row = i;
				col = j;
				found = true;
				break;
			}
		}
	}
	if(!found){
		cout<<1<<'\n';
		return;
	}
	for(int j=col;j<n;j++){
		ans[row][j] = ptr;
		ptr+=2;
	}
	for(int i=row+1;i<n;i++){
		for(int j=0;j<n;j++){
			ans[i][j] = ptr;
			ptr+=2;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<'\n';
	}
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
