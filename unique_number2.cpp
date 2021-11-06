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
	int x = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		x^=arr[i];
	}
	int set_bit = x & -x;
	int num_x = 0,num_y = 0;
	for(int i=0;i<n;i++){
		if(arr[i] & set_bit){
			num_x^=arr[i];
		}else{
			num_y^=arr[i];
		}
	}
	int mini = min(num_x,num_y);
	int maxi = max(num_x,num_y);
	cout << mini <<" "<<maxi<<"\n";
	delete []arr;
	return 0;
}