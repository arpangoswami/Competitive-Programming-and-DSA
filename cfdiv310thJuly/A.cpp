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
	//string s;
	//cin >> s;
	int xA,yA;
	cin >> xA >> yA;
	int xB,yB;
	cin >> xB >> yB;
	int xF,yF;
	cin >> xF >> yF;
	//cout<<xA<<" "<<yA<<" "<<xB<<" "<<yB<<" "<<xF<<" "<<yF<<"\n";
	if(xA != xB && yA != yB){
		cout<<abs(xA-xB)+abs(yA-yB)<<"\n";
		return;
	}else{
		if(xA == xB){
			//cout<<"min"<<min(yA,yB)<<" max: "<<max(yA,yB)<<" yF: "<<yF<<"\n";
			if(xF == xA && yF > min(yA,yB) && yF < max(yA,yB)){
				//cout<<"yolo"<<"\n";
				cout<<abs(xA-xB)+abs(yA-yB)+2<<"\n";
				return;
			}
		}else if(yA == yB){
			if(yF == yA && xF > min(xA,xB) && xF < max(xA,xB)){
				cout<<abs(xA-xB)+abs(yA-yB)+2<<"\n";
				return;
			}
		}
		cout<<abs(xA-xB)+abs(yA-yB)<<"\n";
		return;
	}
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