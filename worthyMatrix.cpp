/*
Chef found a matrix A with N rows (numbered 1 through N) and M columns (numbered 1 through M), where for each row r and column c, 
the cell in row r and column c (denoted by (r,c)) contains an integer Ar,c.

This matrix has two interesting properties:

The integers in each row form a non-decreasing sequence, i.e. for each valid i, Ai,1≤Ai,2≤…≤Ai,M.
The integers in each column also form a non-decreasing sequence, i.e. for each valid j, A1,j≤A2,j≤…≤AN,j.
A K-worthy submatrix is a square submatrix of A, i.e. a submatrix with l rows and l columns, for any integer l, 
such that the average of all the integers in this submatrix is ≥K.

Chef wants you to find the number of K-worthy submatrices of A.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, M and K.
N lines follow. For each valid i, the i-th of these lines contains M space-separated integers Ai,1,Ai,2,Ai,3,…,Ai,M.
Output
For each test case, print a single line containing one integer ― the number of K-worthy submatrices of A.

Constraints
1≤T≤10
1≤N⋅M≤106
N≤M
0≤K≤109
0≤Ar,c≤109 for each valid r,c
the sum of N⋅M over all test cases does not exceed 106
Subtasks
Subtask #1 (15 points): the sum of N⋅M over all test cases does not exceed 103
Subtask #2 (25 points): the sum of N⋅M over all test cases does not exceed 4⋅105
Subtask #3 (60 points): original constraints

Example Input
1
3 3 4
2 2 3
3 4 5
4 5 5
Example Output
7
Explanation
Example case 1: The following are the seven 4-worthy submatrices:

[3445] with average 4; this matrix occurs only once
[4555] with average 4.75; this matrix also occurs only once
[4] with average 4; we find this matrix twice in A
[5] with average 5; we find this matrix 3 times in A
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int calSum(vector<vector<int>> &pref,int sx,int sy,int rx,int ry){
	int ans = pref[rx][ry];
	if(sx > 0){
		ans -= pref[sx-1][ry];
	}
	if(sy > 0){
		ans -= pref[rx][sy-1];
	}
	if(sx > 0 && sy > 0){
		ans += pref[sx-1][sy-1];
	}
	return ans;
}
void solveQuestion(){
	int m,n,k;
	cin >> m >> n >> k;
	vector<vector<int>> arr(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> pref(m,vector<int>(n));
	pref[0][0] = arr[0][0];
	for(int i=1;i<n;i++){
		pref[0][i] = pref[0][i-1] + arr[0][i];
	}
	for(int i=1;i<m;i++){
		pref[i][0] = pref[i-1][0] + arr[i][0];
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			pref[i][j] = pref[i-1][j] + pref[i][j-1] + arr[i][j] - pref[i-1][j-1];
		}
	}
	cout<<"pref: "<<'\n';
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<pref[i][j]<<" ";
		}
		cout<<'\n';
	}
	int ans = 0;
	for(int len=1;len<=m;len++){
		for(int srow=0;srow<=(m-len);srow++){
			int lowCol = 0,highCol = n-len,lans = highCol+1,sum = len*len*k,low = lowCol,high = highCol;
			while(low <= high){
				int mid = (low + high)/2;
				int startX = srow,endX = startX + len - 1,startY = mid,endY = startY + len - 1;
				if(calSum(pref,startX,startY,endX,endY) >= sum){
					lans = mid;
					high = mid-1;
				}else{
					low = mid+1;
				}
			}
			ans += (highCol - lans + 1);
			//cout<<"len: "<<len<<" srow: "<<srow<<" highCol: "<<highCol<<" lans: "<<lans<<'\n';
		}
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}