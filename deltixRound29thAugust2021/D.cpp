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
map<pii,int> andQueries;
map<pii,int> orQueries;
int orQuery(int i,int j){
	if(orQueries.count({i,j})){
		return orQueries[{i,j}];
	}
	if(orQueries.count({j,i})){
		return orQueries[{j,i}];
	}
	cout<<"or "<<i<<" "<<j<<endl;
	int v;
	cin >> v;
	orQueries[{i,j}] = v;
	orQueries[{j,i}] = v;
	return v;
}
int andQuery(int i,int j){
	if(andQueries.count({i,j})){
		return andQueries[{i,j}];
	}
	if(andQueries.count({j,i})){
		return andQueries[{j,i}];
	}
	cout<<"and "<<i<<" "<<j<<endl;
	int v;
	cin >> v;
	andQueries[{i,j}] = v;
	andQueries[{j,i}] = v;
	return v;
}
int getNum(int num,int orq,int andq){
	return num ^ orq ^ andq;
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi arr(n+1);
	int and12 = andQuery(1,2),or12 = orQuery(1,2),sum12 = and12 + or12,and13 = andQuery(1,3),
	or13 = orQuery(1,3),sum13 = and13 + or13,and23 = andQuery(2,3),or23 = orQuery(2,3),sum23 = and23 + or23;
	arr[1] = (sum12 + sum13 - sum23)/2;
	arr[2] = (sum23 + sum12 - sum13)/2;
	arr[3] = (sum23 + sum13 - sum12)/2;
	for(int i=4;i<=n;i++){
		int andQ = andQuery(1,i);
		int orQ = orQuery(1,i);
		arr[i] = getNum(arr[1],orQ,andQ);
	}
	// for(int x:arr){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	sort(arr.begin(),arr.end());
	cout << "finish "<<arr[k]<<"\n"; 
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}