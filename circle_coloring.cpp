#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> ans(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	for(int i=0;i<n;i++) cin >> c[i];
	ans[0] = a[0];
	for(int i=1;i<(n-1);i++){
		if(a[i]!=ans[i-1]){
			ans[i] = a[i];
		}else{
			ans[i] = b[i];
		}
	}
	if(a[n-1] != ans[0] && a[n-1]!= ans[n-2]){
		ans[n-1] = a[n-1];
	}else if(b[n-1] != ans[0] && b[n-1]!= ans[n-2]){
		ans[n-1] = b[n-1];
	}else{
		ans[n-1] = c[n-1];
	}
 	for(int x:ans){
 		cout<<x<<" ";
 	}
 	cout<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}