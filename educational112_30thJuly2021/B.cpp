#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	double height,width;
	cin >> width >> height;
	double x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double h,w;
	cin >> w >> h;
	double ht = y2-y1,wd = x2-x1;
	//cout<<"ht: "<<ht<<" h: "<<h<<" wd: "<<wd<<" w: "<<w<<"\n";
	if((ht + h) > height && (wd + w) > width){
		cout<<"-1\n";
		return;
	}
	double dist = 2e8+1;
	//place topLeft
	double yMove = (height - y2) >= h ? 0 : h - height + y2;

	double xMove = (x1 >= w) ? 0 : w - x1;
	if((ht + h) > height){
		yMove = 1e12;
	}
	if((wd+w) > width){
		xMove = 1e12;
	}
	dist = min(dist,min(xMove,yMove));
	//place topRight
	yMove = (height - y2) >= h ? 0 : h - height + y2;
	xMove = (width - x2) >= w ? 0 : w - width + x2;
	if((ht + h) > height){
		yMove = 1e12;
	}
	if((wd+w) > width){
		xMove = 1e12;
	}
	dist = min(dist,min(xMove,yMove));
	//place bottomLeft
	yMove = (y1 >= h) ? 0 : h-y1;
	xMove = (x1 >= w) ? 0 : w - x1;
	if((ht + h) > height){
		yMove = 1e12;
	}
	if((wd+w) > width){
		xMove = 1e12;
	}
	dist = min(dist,min(xMove,yMove));
	//place bottomRight 
	yMove = (y1 >= h) ? 0 : h-y1;
	xMove = (width - x2) >= w ? 0 : w - width + x2;
	if((ht + h) > height){
		yMove = 1e12;
	}
	if((wd+w) > width){
		xMove = 1e12;
	}
	dist = min(dist,min(xMove,yMove));
	cout<<setprecision(8)<<fixed<<dist<<"\n";
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