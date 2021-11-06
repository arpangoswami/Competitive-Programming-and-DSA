/*
MKBUDGET - Making A Budget
#dynamic-programming
A company uses temporary employees (“temps”) to handle its varying workloads. By doing so, it avoids having to pay for benefits normally provided to its permanent employees. However, the company must pay an employment agency a fixed fee for each temp they hire, as well as paying the temp a fixed amount of severance pay when they are terminated – in addition, of course, to the monthly salary each temp receives. The company has a good understanding of when it needs temporary workers, and how many such workers it will require each month. Depending on the fee paid to the employment agency, the temporary worker’s salary, and the severance pay, it may make sense to retain an unneeded worker for one or more months if it’s known that they will be needed again in the future.

Let’s consider an example. Suppose we know that in March the company will need 10 temps, in April they’ll need 9, and in May they’ll need 11. Suppose a temp earns $500 per month, that the employment agency receives $400 for each temp hired, and $600 is paid as severance to each temp that is terminated. If the company employs just the minimum number of temps required, then their payments will be as follows (we ignore the cost of terminating all employees at the end of the last month):

Illustration
The total cost to the company is $20,400. But suppose they did not terminate the unneeded temp at the end of March, but just let that person remain employed. They would then save $400 in employment agency fees (since they’d need to hire just one additional temp for May), $600 in severance pay, and only have to pay the temp worker $500, for an overall savings of $500.

In this problem you are given, as input, the number of months for which the company is to plan its temp worker budget, the cost of hiring and firing a temp worker, the temp worker’s monthly salary, and the required minimum number of workers needed each month. You are to determine the minimum cost to the company to have at least the required minimum number of workers on hand each month. Assume there are no temporary workers on hand before the first month, and that the cost of terminating the workers at the end of the last month is not to be included in the cost. You may assume that the planning interval will be no longer than 24 months, and the hiring cost, severance pay, and monthly salary for each temp worker is greater than zero.

Input
There will be multiple cases to consider. The input for each case begins with an integer N, the number of months for which planning is required (never larger than 24). This is followed by three integers giving the cost of hiring a worker, the worker’s monthly salary, and the severance pay for a terminated worker. Finally there will appear N integers giving the required minimum number of workers needed in each month. The last case will be followed by a zero.

Output
For each input case, display the case number (1, 2, …) and the minimum cost to the company. Use the format shown in the examples below.

Example
Input:
3 400 500 600 10 9 11
8 400 600 600 11 9 10 14 9 9 13 15
0

Output:
Case 1, cost = $19900
Case 2, cost = $66600
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int hir,sal,sev;
int solve(int idx,int emp,vector<int> &arr,vector<vector<int>> &dp){
	if(idx == arr.size()){
		return 0;
	}
	if(dp[emp][idx]!=-1){
		return dp[emp][idx];
	}
	if(emp >= arr[idx]){
		int ans = 1e15;
		for(int i=arr[idx];i<=emp;i++){
			ans = min(ans,sev * (emp - i) + sal * i + solve(idx+1,i,arr,dp));
		}
		return dp[emp][idx] = ans;
	}
	return dp[emp][idx] = hir * (arr[idx] - emp) + sal * arr[idx] + solve(idx+1,arr[idx],arr,dp);
}
void solveQuestion(int n){
	cin >> hir >> sal >> sev;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int ans = 1e15;
	int minReq = arr[0];
	vector<vector<int>> dp(35,vector<int>(n+1,-1));
	for(int i=minReq;i<=30;i++){
		ans = min(ans,sal * i + hir * i + solve(1,i,arr,dp));
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int cnt = 1;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		cout<<"Case "<<cnt<<", cost = $";
		cnt++;
		solveQuestion(n);
	}
	return 0;
}