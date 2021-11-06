#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
array<ll,10001> arr;
void nthUglyNumber(int n){
	arr[0] = 1LL;
	int l2 = 0,l3 = 0,l5 = 0;
	for(int i=1;i<n;i++){
		arr[i] = min({arr[l2]*2,arr[l3]*3,arr[l5]*5});
		if(arr[i] == arr[l2]*2){
			l2++;
		}if(arr[i] == arr[l3]*3){
			l3++;
		}if(arr[i] == arr[l5] * 5){
			l5++;
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	nthUglyNumber(10001);
	while(test--){
		int n;
		cin>>n;
		cout<<arr[n-1]<<"\n";
	}
	return 0;
}