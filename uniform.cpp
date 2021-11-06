/*
Uniform Problem Code: UNICOLORSolvedSubmit

 
Read problem statements in Russian, Bengali, and Mandarin Chinese as well.
In a school, there are C clubs (numbered 1 through C) that students can participate in.
 Each student can be in zero, one or multiple clubs.

Tomorrow, there is a school assembly and N students (numbered 1 through N) will be standing in a line.
 Each student should wear one of M single-colour shirts provided by the school. The only restriction is that for each club,
  students in this club must wear shirts with the same colour (possibly the same colour for multiple clubs).

Students in the same clubs try to stand near each other. Formally, for each club i, you are given xi segments
 — let's denote them by [l1,r1],[l2,r2],…,[lxi,rxi], where 1≤l1≤r1<l2≤r2<…<lxi≤rxi≤N — such for each valid j,
  the students lj,lj+1,…,rj belong to this club.

Determine the number of ways in which the students can choose the colours of their shirts. Two ways to choose
 colours are considered different if there is at least one student wearing a shirt with a different colour.
  Since this number can be very large, compute it modulo 998,244,353.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers C, N and M.
Then, 2C lines follow. For each valid i, the (2i−1)-th of these lines contains a single integer xi and the 2i-th line contains 2⋅xi space-separated integers
 l1,r1,l2,r2,…,lxi,rxi.
Output
For each test case, print a single line containing one integer — the number of ways to choose colours modulo 998,244,353.

Constraints
1≤T≤10
1≤N,M≤109
1≤C≤1,000
1≤xi≤100 for each valid i
Subtasks
Subtask #1 (30 points): N≤1,000
Subtask #2 (70 points): original constraints

Example Input
1
2 6 3
2
1 2 5 6
1
4 6
Example Output
9
Explanation
Example case 1: Students 5 and 6 are in both clubs, so these two clubs must wear shirts with the same colour.
 Student 3 does not participate in any club and can wear a shirt with any colour out of the three available options.
*/#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD2 = 1e9 + 7;
const int MOD = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
class dsu{
public:
	int n;
	vector<int> parent;
	vector<int> height;
	dsu(int _n){
		n = _n;
		parent.resize(n+1);
		height.resize(n+1);
		for(int i=1;i<=n;i++){
			parent[i] = i;
		}
	}
	int findPar(int x){
		if(parent[x] == x){
			return x;
		}
		int p = findPar(parent[x]);
		parent[x] = p;
		return p;
	}
	void unite(int x,int y){
		int x_par = findPar(x),y_par = findPar(y);
		if(x_par == y_par){
			return;
		}
		if(height[x_par] < height[y_par]){
			parent[x_par] = y_par;
		}else{
			parent[y_par] = x_par;
		}
	}
};
void solveQuestion(){
	int n,m,c;
	cin >> c >> n >> m;
	dsu d(c);
	vector<array<int,3>> arr;
	for(int i=1;i<=c;i++){
		int x;
		cin >> x;
		for(int j=0;j<x;j++){
			int u,v;
			cin >> u >> v;
			arr.push_back({u,v,i});
		}
	}
	sort(arr.begin(),arr.end());
	int cmp = 0;
	int N = arr.size();
	int rem = (arr[0][0] - 1);
	int prevEnd = arr[0][1];
	for(int i=1;i<N;i++){
		if(arr[i][0] <= prevEnd){
			d.unite(arr[i][2],arr[i-1][2]);
			prevEnd = max(prevEnd,arr[i][1]);
		}else{
			rem += (arr[i][0] - prevEnd - 1);
			prevEnd = arr[i][1];
		}
	}
	for(int i=1;i<=c;i++){
		if(d.findPar(i) == i){
			cmp++;
		}
	}
	rem += (n-prevEnd);
	cout<<power(m,cmp + rem)<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}

