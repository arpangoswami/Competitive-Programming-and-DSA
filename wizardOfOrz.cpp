#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	if(n == 1){
		cout<<9<<'\n';
	}else if(n == 2){
		cout<<98<<'\n';
	}else if(n == 3){
		cout<<989<<'\n';
	}else{
		string ans = "989";
		int num = 0;
		for(int i=3;i<n;i++){
			ans.push_back('0' + num);
			num++;
			num %= 10;
		}
		cout<<ans<<'\n';
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