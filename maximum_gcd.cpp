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
		int n;
		cin>>n;
		if(n%2 == 1){
			n--;
		}
		cout<<n/2<<endl;
	}
	return 0;
}