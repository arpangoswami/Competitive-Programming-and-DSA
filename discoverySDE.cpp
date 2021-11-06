#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
map<double,string> denominations;
void pre(){
	denominations[0.01] = "PENNY";
	denominations[0.05] = "NICKEL";
	denominations[0.10] = "DIME";
	denominations[0.25] = "QUARTER";
	denominations[0.50] = "HALF DOLLAR";
	denominations[1.00] = "ONE";
	denominations[2.00] = "TWO";
	denominations[5.00] = "FIVE";
	denominations[10.00] = "TEN";
	denominations[20.00] = "TWENTY";
	denominations[50.00] = "FIFTY";
	denominations[100.00] = "ONE HUNDRED";
}
void solve(double amountLeft,vector<string> &change){
	if(amountLeft <= 0.00){
		return;
	}
	for(auto it = denominations.rbegin();it!=denominations.rend();it++){
		if((*it).first <= amountLeft){
			change.push_back((*it).second);
			solve(amountLeft - (*it).first,change);
			break;
		}
	}
}
void solveQuestion(string s){
	istringstream iss(s);
	double purchasePrice;
	iss >> purchasePrice;
	char delim;
	iss >> delim;
	double paid;
	iss >> paid;
	//cout<<"purchasePrice: "<<purchasePrice<<" paid: "<<paid<<'\n';
	if(purchasePrice > paid){
		cout<<"ERROR"<<'\n';
		return;
	}
	if(purchasePrice == paid){
		cout<<"ZERO"<<'\n';
		return;
	}
	vector<string> change;
	solve(paid - purchasePrice,change);
	sort(change.begin(),change.end());
	int n = change.size();
	for(int i=0;i<n;i++){
		cout<<change[i];
		if(i != n-1){
			cout<<", ";
		}
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	pre();
	string s;
	while(cin >> s){
		solveQuestion(s);
	}
	return 0;
}