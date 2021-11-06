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
		int n;
		cin >> n;
		int size1 = n,size2 = n;
		string a,b;
		cin >> a >> b;
		if(a[n-1] == '1'){
			a.push_back('0');
			size1++;
		}
		if(b[n-1] == '1'){
			b.push_back('0');
			size2++;
		}
		vector<int> sol1;
		vector<int> sol2;
		for(int i=0;i<(size1-1);i++){
			if(a[i]!=a[i+1]){
				sol1.push_back(i+1);
			}
		}
		for(int i=0;i<(size2-1);i++){
			if(b[i]!=b[i+1]){
				sol2.push_back(i+1);
			}
		}
		cout << (sol1.size() + sol2.size())<<" ";
		for(int x:sol1){
			cout<<x<<" ";
		}
		int sz = sol2.size();
		for(int i=sz-1;i>=0;i--){
			cout<<sol2[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}