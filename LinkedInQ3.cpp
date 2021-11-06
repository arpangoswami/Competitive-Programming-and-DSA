#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct Customer{
	int start;
	int finish;
	int volume;
	Customer():start(0),finish(0),volume(0){

	}
	Customer(int st,int fin,int vol):start(st),finish(fin),volume(vol){

	}
};
bool comp(Customer &c1,Customer &c2){
	if(c1.finish == c2.finish){
		return c1.volume > c2.volume;
	}
	return c1.finish < c2.finish
}
int solve(vector<vector<int>> &dp,)
int phoneCalls(vector<int> start,vector<int> duration,vector<int> volume){
	int n = start.size();
	if(n == 0){
		return 0;
	}
	for(int i=0;i<n;i++){
		cust[i] = Customer(start[i],duration + start[i],volume[i]);
	}
	sort(cust.begin(),cust.end(),comp);
	vector<vector<int>> dp(n+1,vector<int>(2,-1));
	return max(volume[0] + solve(1,1,dp),solve(1,0,dp));
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> start(n),duration(n),volume(n);
	vector<Customer> cust(n);
	for(int i=0;i<n;i++){
		cin >> start[i] >> duration[i] >> volume[i];
	}
	int ans = phoneCalls(start,duration,volume);
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