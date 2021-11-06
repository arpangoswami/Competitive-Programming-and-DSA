#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int ans = 0,curr_gap = 0;
	bool found = false;
	for(int x:arr){
		if(x == 1){
			if(found){
				ans += curr_gap;
				curr_gap = 0;
			}else{
				found = true;
			}
		}else{
			if(found){
				curr_gap++;
			}
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}