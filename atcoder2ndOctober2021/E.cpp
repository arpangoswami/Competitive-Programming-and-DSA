#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
const int MOD = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> prefAdd(n-1);
}
pair<int,int> selectPackages(int truckSpace,int numPackages,vector<int> packageSpace){
	if(truckSpace < 30){
		return {-1,-1};
	}
	truckSpace -= 30;
	vector<pair<int,int>> extra(numPackages);
	for(int i=0;i<numPackages;i++){
		extra[i] = {packageSpace[i],i};
	}
	sort(extra.begin(),extra.end());
	if(extra.size() < 2){
		return {-1,-1};
	}
	if(extra[0].first + extra[1].first > truckSpace){
		return {-1,-1};
	}
	pair<int,int> ans = {-1,-1};
	int closest = 0;
	int i=0,j=numPackages-1;
	while(i < j){
		int sum = (extra[i].first + extra[j].first);
		if(sum > truckSpace){
			j--;
			continue;
		}
		if(sum > closest){
			closest = sum;
			ans = {extra[i].second,extra[j].second};
		}
		if(sum == truckSpace){
			return ans;
		}else if(sum < truckSpace){
			i++;
		}
	}
	return ans;
}
bool check(long mid,long order,const vector<long> &inventory){
	int N = inventory.size();
	long pick = 0;
	for(int i=N-1;i>=0 && inventory[i] >= mid;i--){
		pick += (inventory[i] - mid + 1);
	}
	return pick >= order;
}
long generateProfit(long mid,long order,const vector<long> &inventory){
	long profit = 0;
	long picked = 0;
	int N = inventory.size();
	for(int i=N-1;i>=0 && order > 0 && inventory[i] > mid;i--){
		long toPick = inventory[i] - mid;
		long add = (inventory[i] * (inventory[i]+1))/2;
		long sub = (mid * (mid+1))/2;
		profit += (add - sub);
		order -= toPick;
	}
	profit += (order * mid);
	return profit;
}
long highestProfit(int numSuppliers,vector<long> inventory,long order){
	sort(inventory.begin(),inventory.end());
	long profit = 0;
	long low = 0,high = inventory.back();
	while(low <= high){
		long mid = low + (high-low)/2;
		if(check(mid,order,inventory)){
			profit = generateProfit(mid,order,inventory);
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return profit;
}
// long highestProfit(int numSuppliers,vector<long> inventory,long order){
// 	priority_queue
// }
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	// Boost();
	// int tt = 1;
	// //cin >> tt;
	// while(tt-- > 0){
	// 	solveQuestion();
	// }
	cout << highestProfit(4,{2,2,2,2},5)<<"\n";
	return 0;
}