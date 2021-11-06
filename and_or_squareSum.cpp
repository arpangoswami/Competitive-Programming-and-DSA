#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> bits(21);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		for(int j=0;j<=20;j++){
			if((arr[i] >> j) & 1){
				bits[j]++;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		int toAdd = 0;
		for(int j=0;j<=20;j++){
			if(bits[j] > 0){
				toAdd += (1 << j);
				bits[j]--;
			}
		}
		ans += (toAdd * toAdd);
	}
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}