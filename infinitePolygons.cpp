#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
double pi = acos(-1.00);
void solveQuestion(){
	int n;
	cin >> n;
	double ratio = (1 - cos(((n-2)*pi)/n))/2;
	//cout<<"ratio: "<<ratio<<'\n';
	double ans = (1.00/(1.00 - ratio));
	cout<<fixed<<setprecision(7)<<ans<<'\n';
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