#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll x,y;
		cin>>x>>y;
		ll a,b;
		cin>>a>>b;
		if(2*a <= b){
			cout<<(x+y)*a<<"\n";
		}else{
			if(x > y){
				swap(x,y);
			}
			cout<< (x*b + (y-x)*a) <<"\n";
		}
	}
	return 0;
}