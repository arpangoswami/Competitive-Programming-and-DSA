#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	vi arr(n);
	int cnt0 = 0,cnt1 = 0;
	for(int &i:arr){
		cin >> i;
		if(i){
			cnt1++;
		}else{
			cnt0++;
		}
	}
	while(q--){
		int type,k;
		cin >> type >> k;
		if(type == 1){
			int prev = arr[k-1];
			if(prev == 1){
				cnt1--;
				cnt0++;
			}else{
				cnt0--;
				cnt1++;
			}
			arr[k-1] = prev ^ 1;
		}else{
			if(cnt >= k){
				cout<<1<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}
	}

}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}