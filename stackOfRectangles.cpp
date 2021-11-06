#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
double area(double a,double b,double c){
	double semi = (a+b+c)/2.0;
	return sqrt(semi*(semi-a)*(semi-b)*(semi-c));
}
void solveQuestion(){
	double a,b,c,k;
	cin >> a >> b >> c >> k;
	double ar = area(a,b,c);
	double height = (2*ar)/c;
	double h = (height/(k+1));
	double ans = (k * ar)/(k+1);
	cout << fixed << setprecision(7) << ans << '\n';
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