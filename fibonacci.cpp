#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int first = 0, second = 1;
	if(n == 0){
		cout<<first<<"\n";
	}else if(n == 1){
		cout<<second<<"\n";
	}else{
		// fib(n) = fib(n-1) + fib(n-2)
		// 0 1 1 2 3 5 8
		int ans;
		for(int i=2;i<=n;i++){
			ans = first + second;
			first = second;
			second = ans;
		}
		cout<<ans<<"\n";
		vector<int> arr(n+1);
		arr[0] = 0;
		arr[1] = 1;
		for(int i=2;i<=n;i++){
			arr[i] = arr[i-1] + arr[i-2];
		}
		for(int x:arr){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}