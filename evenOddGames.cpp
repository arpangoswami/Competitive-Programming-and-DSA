#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end(),greater<int>());
	int alice = 0,bob = 0;
	for(int i=0;i<n;i++){
		if(i%2 == 0){
			if(arr[i] % 2 == 0){
				alice += arr[i];
			}
		}else{
			if(arr[i] % 2 == 1){
				bob += arr[i];
			}
		}
	}
	if(alice > bob){
		cout<<"Alice\n";
	}else if(bob > alice){
		cout<<"Bob\n";
	}else{
		cout<<"Tie\n";
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