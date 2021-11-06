#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int x,y,z;
		cin>>x>>y>>z;
		if(x!=y && y!=z && x!=z){
			cout<<"NO"<<"\n";
		}else{
			if(x == y){
				if(z > x){
					cout << "NO" <<"\n";
				}else{
					cout<<"YES" <<"\n";
					cout<< x << " " << z << " " << z << "\n";
				}
			}
			else if(y == z){
				if(x > z){
					cout << "NO" <<"\n";
				}else{
					cout<<"YES" <<"\n";
					cout<< x << " " << x << " " << z << "\n";
				}
			}else if(x == z){
				if(y > z){
					cout << "NO" <<"\n";
				}
				else{
					cout<<"YES"<<"\n";
					cout << x <<" "<<y<<" "<<y<<"\n";
				}
			}
		}
	}
	return 0;
}