#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
void solveQuestion(){
	int n,x;
	cin >> n >> x;
	if((n & 1) && x == 0){
		cout<<"-1\n";
		return;
	}
	if(x >= n){
		cout<<"1\n";
		return;
	}
	vector<int> values;
	int ans = 0;
	if(n & 1){
		ans++;
		x--;
	}
	for(int i=1;i<30;i++){
		if((n >> i) & 1){
			if(i & 1){
				values.push_back(1 << i);
			}else{
				values.push_back(1 << (i-1));
				values.push_back(1 << (i-1));
			}
		}
	}
	int N = values.size();
	int left = 0,currSum = 0,maxWindow = 0;
	for(int i=0;i<N;i++){
		currSum += values[i];
		while(left <= i && currSum > x){
			currSum -= values[left];
			left++;
		}
		maxWindow = max(maxWindow,i-left+1);
	}
	if(ans > 0){
		ans += (N-maxWindow);
	}else if(maxWindow >= 1){
		ans += (N-maxWindow);
		ans++;
	}else{
		ans += N;
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}