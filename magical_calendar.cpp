#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll color,week;
		cin>>color>>week;
		if(week >= color){
			cout<<(color*(color-1))/2 + 1<<"\n";
		}else{
			cout<<(week*(week+1))/2<<"\n";
		}
	}
	return 0;
}