#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int ones = 0,twos = 0;
	for(int i=0;i<n;i++){
		int x = arr[i];
		twos |= (ones & x);
		ones ^= x;
		int not_threes = ~(ones & twos);
		ones &= not_threes;
		twos &= not_threes;
	}
	cout << ones << "\n";
	delete []arr;
	return 0;
}