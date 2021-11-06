#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void changeArray(int arr[]){
	for(int i=0;i<100;i++){
		arr[i] = i+1;
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int arr[100] = {0};
	changeArray(arr);
	for(int i=0;i<100;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}