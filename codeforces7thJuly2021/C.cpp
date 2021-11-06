#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const long double scale = 1e6;
long double solve(int c,int m,int p,int v){
	long double ans = (p/scale);
	if(c > 0){
		if(c > v){
			if(m > 0)
				ans += (c/scale)*(1+solve(c-v,m+(v/2),p+(v/2),v));
			else
				ans += (c/scale)*(1+solve(c-v,0,p+v,v));
		}else{
			if(m > 0)
				ans += (c/scale)*(1+solve(0,m+(c/2),p+(c/2),v));
			else
				ans += (c/scale)*(1+solve(0,0,p+c,v));
		}
	}
	if(m > 0){
		if(m > v){
			if(c > 0)
				ans += (m/scale)*(1+solve(c+(v/2),m-v,p+(v/2),v));
			else
				ans += (m/scale)*(1+solve(0,m-v,p+v,v));
		}else{
			if(c > 0)
				ans += (m/scale)*(1+solve(c+(m/2),0,p+(m/2),v));
			else
				ans += (m/scale)*(1+solve(0,0,p+m,v));
		}
	}
	
	return ans;
}
void solveQuestion(){
	long double cd,md,pd,vd;
	cin >> cd >> md >> pd >> vd;
	int c = round(cd*scale),m = round(md*scale),p = round(pd*scale),v = round(vd*scale);
	long double ans = solve(c,m,p,v);
	cout<<fixed<<setprecision(12)<<ans<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}