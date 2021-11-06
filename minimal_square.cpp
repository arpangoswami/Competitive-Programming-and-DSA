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
		int a,b;
		cin>>a>>b;
		int square_side = min(2*a,2*b);
		square_side = max({square_side,a,b});
		cout<<square_side*square_side<<"\n";
	}
	return 0;
}