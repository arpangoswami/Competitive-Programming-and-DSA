#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int sum = 0;
	int n;
	cin >> n;
	vi arr(n);
	bool allTwo = true;
	for(int &i:arr){
		cin >> i;
		sum += i;
		if(i == 1){
			allTwo = false;
		}
	}
	if(sum % 2){
		cout<<"NO"<<'\n';
	}else{
		if(n % 2 == 0){
			cout<<"YES"<<'\n';
		}else{
			if(allTwo){
				cout<<"NO"<<'\n';
			}else{
				cout<<"YES"<<'\n';
			}
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