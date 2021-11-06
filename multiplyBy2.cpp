#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		bool flag = true;
		int steps = 0;
		ll temp = n;
		while(temp > 1){
			if(temp%6 == 0){
				temp/=6;
				steps++;
			}else{
				temp*=2;
				steps++;
			}
			if(temp >= n && temp%6 != 0){
				flag = false;
				break; 
			}
		}
		if(flag){
			cout<<steps<<"\n";
		}
		else{
			cout<<-1<<"\n";
		}
	}
	return 0;
}