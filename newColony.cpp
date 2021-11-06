#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	for(int i=1;i<=k;i++){
		int pos = -1;
		for(int i=0;i<(n-1);i++){
			if(arr[i] < arr[i+1]){
				pos = (i+1);
				arr[i]++;
				break;
			}
		}
		if(pos == -1){
			cout<<-1<<'\n';
			return;
		}
		if(i == k){
			cout<<pos<<'\n';
		}
	}
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