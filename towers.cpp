/*
Towers
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.

You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?

Input

The first input line contains an integer n: the number of cubes.

The next line contains n integers k1,k2,…,kn: the sizes of the cubes.

Output

Print one integer: the minimum number of towers.

Constraints
1≤n≤2⋅105
1≤ki≤109
Example

Input:
5
3 8 2 1 5

Output:
2
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<int> ans;
	ans.push_back(arr[0]);
	for(int i=1;i<n;i++){
		int ht = arr[i];
		if(ht >= ans.back()){
			ans.push_back(ht);
		}else{
			int idx = upper_bound(ans.begin(),ans.end(),ht) - ans.begin();
			ans[idx] = ht;
		}
	}
	cout<<ans.size();
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