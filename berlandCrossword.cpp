#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(int n,int u,int l,int d,int r,int corners){
	int tl = (corners >> 0) & 1;
	int tr = (corners >> 1) & 1;
	int bl = (corners >> 2) & 1;
	int br = (corners >> 3) & 1;
	int up = 0,left = 0,down = 0,right = 0;
	if(tl){
		up++;
		left++;
	}
	if(tr){
		up++;
		right++;
	}
	if(bl){
		down++;
		left++;
	}
	if(br){
		down++;
		right++;
	}
	if(u >= up && u <= (up + n-2) && l >= left && l <= (left + n - 2) && r >= right && r <= (right + n - 2) && d >= down && d <= (down + n - 2)){
		return true;
	}
	return false;
}
void solveQuestion(){
	int n,u,r,d,l;
	cin >> n >> u >> r >> d >> l;
	if(max({u,l,d,r}) <= (n-2)){
		cout<<"YES"<<'\n';
		return;
	}
	for(int i=0;i<=15;i++){
		if(check(n,u,l,d,r,i)){
			cout<<"YES"<<'\n';
			return;
		}
	}
	cout<<"NO"<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}