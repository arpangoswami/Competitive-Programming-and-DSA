#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vi miners;
vi diamond;
void solveQuestion(){
	int n;
	cin >> n;
	int i=0,j=0;
	miners.resize(n);
	diamond.resize(n);
	for(int k=0;k<2*n;k++){
		int x,y;
		cin >> x >> y;
		if(x == 0){
			miners[i++] = abs(y);
		}else{
			diamond[j++] = abs(x);
		}
	}
	sort(miners.begin(),miners.end());
	sort(diamond.begin(),diamond.end());
	double ans = 0.00;
	for(int i=0;i<n;i++){
		ans += sqrt(diamond[i]*diamond[i] + miners[i]*miners[i]);
	}
	cout<<fixed<<setprecision(10)<<ans<<'\n';
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