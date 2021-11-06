/*
Maximum Building I
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You are given a map of a forest where some squares are empty and some squares have trees.

What is the maximum area of a rectangular building that can be placed in the forest so that no trees must be cut down?

Input

The first input line contains integers n and m: the size of the forest.

After this, the forest is described. Each square is empty (.) or has trees (*).

Input

Print the maximum area of a rectangular building.

Constraints
1≤n,m≤1000
Example

Input:
4 7
...*.*.
.*.....
.......
......*

Output:
12
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int calMaxArea(vector<int> &arr,int n){
	stack<int> st;
	int maxArea = 0;
	st.push(0);
	for(int i=1;i<n;i++){
		if(arr[i] >= arr[st.top()]){
			st.push(i);
		}else{
			while(!st.empty() && arr[i] < arr[st.top()]){
				int tp = st.top();
				st.pop();
				if(st.empty()){
					maxArea = max(maxArea,arr[tp]*i);
				}else{
					maxArea = max(maxArea,arr[tp]*(i-st.top()-1));
				}
			}
			st.push(i);
		}
	}
	while(!st.empty()){
		int tp = st.top();
		st.pop();
		if(st.empty()){
			maxArea = max(maxArea,arr[tp]*n);
		}else{
			maxArea = max(maxArea,arr[tp]*(n-st.top()-1));
		}
	}
	return maxArea;
}
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	vector<string> grid(m);
	for(int i=0;i<m;i++){
		cin >> grid[i];
	}
	vector<int> arr(n,0);
	for(int i=0;i<n;i++){
		if(grid[0][i] == '.'){
			arr[i] = 1;
		}
	}
	int ans = calMaxArea(arr,n);
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == '*'){
				arr[j] = 0;
			}else{
				arr[j]++;
			}
		}
		ans = max(ans,calMaxArea(arr,n));
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