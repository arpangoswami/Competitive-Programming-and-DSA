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
		ll a,b,n;
		cin>>a>>b>>n;
		if(a>b){
			swap(a,b);
		}
		int steps = 0;
		if(b>n){
			cout<<0<<endl;
		}else{
			while(a<=n && b<=n){
				a+=b;
				steps++;
				if(a > n){
					break;
				}
				if(a + b > n){
					steps++;
					break;
				}
				b+=a;
				steps++;
				if(b > n){
					break;
				}
				if(b + a > n){
					steps++;
					break;
				}
			}
			cout<<steps<<endl;
		}
	}
	return 0;
}