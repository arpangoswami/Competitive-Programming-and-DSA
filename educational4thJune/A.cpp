#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQ(){
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	int w1 = max(a[0],a[1]),w2 = max(a[2],a[3]);
	sort(a,a+4);
	if((w1 == a[3] && w2 == a[2]) || (w1 == a[2] && w2 == a[3])){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	int tt;
	cin >> tt;
	while(tt-- > 0){
		solveQ();
	}
	return 0;
}