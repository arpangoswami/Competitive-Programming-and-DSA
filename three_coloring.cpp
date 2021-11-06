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
vector<pii> even;
vector<pii> odd;
int i,j;
void outputBox(int col){
	if(col % 2 == 0){
		if(i < odd.size()){
			cout<<1<<" "<<odd[i].first<<" "<<odd[i].second<<endl;
			i++;
		}else{
			cout<<3<<" "<<even[j].first<<" "<<even[j].second<<endl;
			j++;
		}
	}else{
		if(j < even.size()){
			cout<<2<<" "<<even[j].first<<" "<<even[j].second<<endl;
			j++;
		}else{
			int c = (col == 1) ? 3 : 1;
			cout<<c<<" "<<odd[i].first<<" "<<odd[i].second<<endl;
			i++;
		}
	}
	cout.flush();
}
void solveQuestion(){
	int n;
	cin >> n;
	i = 0,j = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(((i+j) % 2) == 0){
				even.push_back({i,j});
			}else{
				odd.push_back({i,j});
			}
		}
	}
	int queries = n*n;
	while(queries){
		queries--;
		int col;
		cin >> col;
		outputBox(col);
	}
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