#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const int MOD = 1e9 + 7;
vector<int> fact(100001);
int nCr(int N,int r){
	if(r > N || r < 0 || N < 0){
		return 0;
	}
	return fact[N]/(fact[N-r]*fact[r]);
}
void pre(){
	fact[0] = 1;
	for(int i=1;i<=100000;i++){
		fact[i] = (fact[i-1] * i)%MOD;
	}
}
int countWays(vector<int> arr){
	if(arr.size() <= 2){
		return 1;
	}
	int N = arr.size();
	vector<int> leftSubTree,rightSubTree;
	int root = arr[0];
	for(int i=1;i<arr.size();i++){
		if(arr[i] < root){
			leftSubTree.push_back(arr[i]);
		}else{
			rightSubTree.push_back(arr[i]);
		}
	}
	return nCr(N-1,leftSubTree.size()) * countWays(leftSubTree) * countWays(rightSubTree);
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	pre();
	string s;
	getline(cin,s);
	istringstream iss(s);
	int N;
	vector<int> arr;
	while(iss >> N){
		arr.push_back(N);
	}
	cout<<countWays(arr) - 1<<"\n";
	return 0;
}