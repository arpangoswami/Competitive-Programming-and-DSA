#include <bits/stdc++.h>
#define int long long
using namespace std;
int hash_map[1000001];
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int *arr = new int[n];
	memset(hash_map,0,sizeof(hash_map));
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		hash_map[x]++;
	}
	int ptr = 0;
	for(int i=0;i<=1000000;i++){
		while(hash_map[i]>0){
			arr[ptr++] = i;
			hash_map[i]--;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	delete []arr;
	return 0;
}