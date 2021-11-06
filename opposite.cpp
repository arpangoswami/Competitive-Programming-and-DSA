#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
double pi = acos(-1.0);
void solveQuestion(){
	double n;
	double x,y;
	double xmid,ymid;
	cin >> n >> x >> y >> xmid >> ymid;
	double centreX = (x + xmid)/2.0;
	double centreY = (y + ymid)/2.0;
	double angle = (2*pi)/n;
	double x_dash = ((x - centreX)*cos(angle) - (y-centreY)*sin(angle)) + centreX;
	double y_dash = ((x - centreX)*sin(angle) + (y-centreY)*cos(angle)) + centreY;
	cout << fixed << setprecision(9) << x_dash << " " << y_dash;
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