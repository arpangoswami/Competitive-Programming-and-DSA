#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int w,h,n;
	cin >> w >> h >> n;
	int twoPow = 0;
	while(w % 2 == 0){
		twoPow++;
		w/=2;
	}
	while(h % 2 == 0){
		twoPow++;
		h/=2;
	}
	if(1<<(twoPow) >= n){
		cout<<"YES"<<'\n';
	}else{
		cout<<"NO\n";
	}
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