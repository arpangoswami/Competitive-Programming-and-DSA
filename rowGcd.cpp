#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vi arr1(n);
	vi arr2(m);
	for(int &i:arr1){
		cin >> i;
	}
	for(int &i:arr2){
		cin >> i;
	}
	if(n == 1){
		for(int i:arr2){
			cout<<arr1[0] + i<<" ";
		}
		return;
	}
	int cal = abs(arr1[1] - arr1[0]);
	for(int i=2;i<n;i++){
		cal = __gcd(abs(arr1[i] - arr1[0]),cal);
	}
	for(int i=0;i<m;i++){
		cout<<__gcd(arr1[0] + arr2[i],cal)<<" ";
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