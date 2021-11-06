#include <bits/stdc++.h>
#define int long long 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	string s;
	cin >> n >> s;
	vi arr(n);
	map<pii,int> mp;
	int dCnt = 0;
	int kCnt = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'K'){
			kCnt++;
		}else if(s[i] == 'D'){
			dCnt++;
		}
		if(dCnt == 0){
			arr[i] = kCnt;
		}else if(kCnt == 0){
			arr[i] = dCnt;
		}else{
			int g = __gcd(dCnt,kCnt);
			// if(i == 4){
			// 	cout<<"dCnt: "<<dCnt<<" kCnt: "<<kCnt<<"\n";
			// }
			mp[{dCnt/g,kCnt/g}]++;
			arr[i] = mp[{dCnt/g,kCnt/g}];
		}
	}
	for(int x:arr){
		cout<<x<<" ";
	}
	cout<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	int tt;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}