#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int h,c,t;
	cin >> h >> c >> t;
	if(t == h){
		cout<<1<<'\n';
		return;
	}
	int cups = 2LL;
	double tav = (h+c)/2.0;
	double diff = abs(t - tav);
	if(tav >= t){
		cout<<2<<'\n';
		return;
	}else{
		double cold = (double)(t - h)/(h+c-2*t);
		if(cold - (int)cold == 0.0){
			cout<<2*cold+1<<'\n';
		}else{
			int cl = (int)cold,cld = cl+1;
			double temp1 = (double)((cl+1)*h + cl*c)/(2*cl+1);
			double temp2 = (double)((cld+1)*h + cld*c)/(2*cld+1);
			double diff1 = abs((double)t - (temp1));
			double diff2 = abs((double)t - temp2);
			if(diff1 <= diff2){
				cout<<2*cl+1<<'\n';
			}else{
				cout<<2*cld+1<<'\n';
			}
		}
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