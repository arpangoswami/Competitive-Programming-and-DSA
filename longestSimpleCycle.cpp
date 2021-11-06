#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> length(n);
	vector<int> arr(n);
	vector<int> brr(n);
	for(int &i:length){
		cin >> i;
	}
	for(int &i:arr){
		cin >> i;
	}
	for(int &i:brr){
		cin >> i;
	}
	int ans = 0,curr = length[n-1] - 1;
	for(int i=n-1;i>0;i--){
		int a = arr[i];
		int b = brr[i];
		if(a != b){
			curr += 2;
			int top = (i == 1) ? 0 : min(a,b) - 1;
			int bot = (i == 1) ? 0 : length[i-1] - max(a,b);
			ans = max(ans,curr + abs(a-b));
			curr += (top + bot);
		}else{
			curr += 2;
			ans = max(ans,curr);
			curr = length[i-1] - 1;
		}
		curr = max(curr,length[i-1]-1);
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}