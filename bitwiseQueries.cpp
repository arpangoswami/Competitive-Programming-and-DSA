#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	cout<<"AND 1 2"<<endl;
	cout.flush();
	int andVal12 = 0,xorVal12 = 0,andVal23 = 0,xorVal23 = 0,andVal13 = 0,xorVal13 = 0;
	cin >> andVal12;
	cout<<"XOR 1 2"<<endl;
	cout.flush();
	cin >> xorVal12;
	int sum12 = 0,sum23 = 0,sum13 = 0;
	sum12 = xorVal12 + 2 * (andVal12);
	cout<<"AND 2 3"<<endl;
	cout.flush();
	cin >> andVal23;
	cout<<"XOR 2 3"<<endl;
	cout.flush();
	cin >> xorVal23;
	sum23 = xorVal23 + 2 * andVal23;
	xorVal13 = xorVal12 ^ xorVal23;
	cout<<"AND 1 3"<<endl;
	cin >> andVal13;
	cout.flush();
	sum13 = xorVal13 + 2*andVal13;
	arr[0] = (sum12 + sum13 - sum23)/2;
	arr[1] = (sum23 + sum12 - sum13)/2;
	arr[2] = (sum13 + sum23 - sum12)/2;
	for(int i=4;i<=n;i++){
		cout<<"XOR "<<1<<" "<<i<<endl;
		cout.flush();
		int val = 0;
		int input;
		cin >> input;
		for(int i=0;i<=16;i++){
			if((arr[0] >> i) & 1){
				if(((input >> i) & 1) == 0){
					val += (1 << i);
				}
			}else{
				if((input >> i) & 1){
					val += (1 << i);
				}
			}
		}
		arr[i-1] = val;
	}
	cout<<"! ";
	for(int x:arr){
		cout<<x<<" ";
	}
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