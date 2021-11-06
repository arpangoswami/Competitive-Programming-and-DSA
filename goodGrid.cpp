#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,x;
	cin >> n >> x;
	if(x <= n || x % n == 0){
		cout<<"Yes"<<'\n';
	}else{
		for(int i=2;i<n;i++){
			if(x % i == 0){
				int div = x/i;
				if(div <= (n-1)){
					cout<<"Yes"<<'\n';
					return;
				}
			}
		}
		cout<<"No"<<'\n';
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