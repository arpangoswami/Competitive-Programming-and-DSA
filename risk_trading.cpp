#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
double round(double var) 
{ 
    double value = (int)(var * 100 + .5); 
    return (double)value / 100; 
} 
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<double> probs(n);
	vector<double> profits(n);
	vector<double> losses(n);
	for(int i=0;i<n;i++){
		cin >> probs[i];
	}
	for(int i=0;i<n;i++){
		cin >> profits[i];
	}
	for(int i=0;i<n;i++){
		cin >> losses[i];
	}
	vector<double> prob_profit(n);
	for(int i=0;i<n;i++){
		prob_profit[i] = probs[i] * profits[i] - (1 - probs[i]) * losses[i];
	}
	sort(prob_profit.begin(),prob_profit.end(),greater<double>());
	int x = min(n,m);
	double ans = 0.00;
	for(int i=0;i<x;i++){
		if(prob_profit[i] > 0.00){
			ans += prob_profit[i];
		}else{
			break;
		}
	}
	cout<<fixed<<setprecision(2)<<round(ans);
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