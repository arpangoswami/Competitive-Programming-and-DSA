#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	int sum = 0;
	vi arr1(n1);
	vi arr2(n2);
	vi arr3(n3);
	int mini = 1e9;
	for(int &i:arr1){
		cin >> i;
		sum += i;
		mini = min(mini,i);
	}
	for(int &i:arr1){
		cin >> i;
		sum += i;
		mini = min(mini,i);
	}
	for(int &i:arr2){
		cin >> i;
		sum += i;
		mini = min(mini,i);
	}
	for(int &i:arr3){
		cin >> i;
		sum += i;
		mini = min(mini,i); 
	}
	sum -= (n1+n2+n3-1)*mini;
	cout<<sum<<'\n';
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