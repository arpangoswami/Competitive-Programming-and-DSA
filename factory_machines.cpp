/*
Factory Machines
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
A factory has n machines which can be used to make products. Your goal is to make a total of t products.

For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.

What is the shortest time needed to make t products?

Input

The first input line has two integers n and t: the number of machines and products.

The next line has n integers k1,k2,…,kn: the time needed to make a product using each machine.

Output

Print one integer: the minimum time needed to make t products.

Constraints
1≤n≤2⋅105
1≤t≤109
1≤ki≤109
Example

Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(int maxTime,vector<int> &arr,int n,int tasks){
	int cnt = 0;
	for(int i=0;i<n;i++){
		cnt += (maxTime/arr[i]);
	}
	return cnt >= tasks;
}
void solveQuestion(){
	int n,t;
	cin >> n >> t;
	vector<int> arr(n);
	int minm = 1e9+1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		minm = min(minm,arr[i]);
	}
	int low = 0,high = minm*t,ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid,arr,n,t)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		solveQuestion();
	}
	return 0;
}