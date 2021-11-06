#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf = 1e9;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	int inc = 1e9+1,dec = 1e9+1;
	for(int i=1;i<n;i++){
		if(arr[i] >= arr[i-1]){
			int diff = arr[i] - arr[i-1];
			if(diff != inc){
				if(inc > inf){
					inc = diff;
				}else{
					cout << -1 << '\n';
					return;
				}
			}
		}else{
			int diff = arr[i-1] - arr[i];
			if(diff != dec){
				if(dec > inf){
					dec = diff;
				}else{
					cout << -1 << '\n';
					return;
				}
			}
		}
	}
	if(dec > inf || inc > inf){
		cout << 0 << '\n';
		return;
	}
	if(inc + dec <= *max_element(arr.begin(),arr.end())){
		// as mod m in each step hence all values must lie in range 0...m-1
		cout << -1 << '\n';
		return;
	}
	cout<<inc + dec<<" "<<inc<<'\n';
	
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