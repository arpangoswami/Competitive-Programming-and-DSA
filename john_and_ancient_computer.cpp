#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll a,b;
		cin>>a>>b;
		bool flag = true;
		int steps = 0;
		while(a != b){
			if(a<b){
				if(a*8<=b){
					steps++;
					a*=8;
				}else if(a*4<=b){
					steps++;
					a*=4;
				}
				else if(a*2<=b){
					steps++;
					a*=2;
				}
				else{
					flag = false;
					cout<<-1<<endl;
					break;
				}
			}
			if(a>b){
				if(a/b >= 8 && a%8 == 0){
					a/=8;
					steps++;
				}else if(a/b >=4 && a%4 == 0){
					a/=4;
					steps++;
				}
				else if(a/b>=2 && a%2 == 0){
					a/=2;
					steps++;
				}
				else{
					flag = false;
					cout<<-1<<endl;
					break;
				}
			}
		}
		if(flag)
		cout<<steps<<endl;
	}
	return 0;
}