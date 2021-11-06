#include <iostream>
#include <vector>
#include<cmath>
#define int unsigned long long
using namespace std;
vector<int> arr(1e6+1,0);
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test;
	cin>>test;
	for(int i=1;i<=1e6;i++){
		arr[i] = i*i;
	}
	int s = 1;
	for(int i=2;i<=1e6;i++){
		arr[i] += s;
		int a = (i*(i+1))/2;
		s += a;
	}
	while(test--){
		int u;
		cin >> u;
		cout<<arr[u]<<"\n";
	}
	return 0;
}