#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQ(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int already = 0;
	int i=0,j=n-1;
	while(i < j){
		if(s[i] != s[j]){
			already++;
		}
		i++;
		j--;
	}
	cout << abs(k - already) << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}