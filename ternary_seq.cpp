#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int x1,y1,z1,x2,y2,z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	int ans = 0;
	int addT = min(z1,y2);//2 first 1 second
	z1-=addT;
	y2-=addT;
	ans += 2*addT;
	addT = min(z1+x1,z2);//2 & 0 first , 2second
	z2-=addT;
	addT = min(y1,x2+y2);//1 first,0 & 1 second;
	y1-=addT;
	addT = min(y1,z2);
	ans-= 2*addT;
	cout<<ans<<"\n";
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