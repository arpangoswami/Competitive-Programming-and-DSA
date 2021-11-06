#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQ(){
	
	int n,k,s;
	cin >> n >> k >> s;
	int time1 = (k-1) + (n+1);
	int time2 = (k-1) + (k - s) + (n-s+1);
	cout<<min(time1,time2)<<"\n";

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