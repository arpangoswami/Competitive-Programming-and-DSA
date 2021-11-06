/*https://codeforces.com/problemset/problem/1534/D
D. Lost Tree
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is an interactive problem.

Little Dormi was faced with an awkward problem at the carnival: he has to guess the edges of an unweighted tree of n nodes! The nodes of the tree are numbered from 1 to n.

The game master only allows him to ask one type of question:

Little Dormi picks a node r (1≤r≤n), and the game master will reply with an array d1,d2,…,dn, where di is the length of the shortest path from node r to i, for all 1≤i≤n.
Additionally, to make the game unfair challenge Little Dormi the game master will allow at most ⌈n2⌉ questions, where ⌈x⌉ denotes the smallest integer greater than or equal to x.

Faced with the stomach-churning possibility of not being able to guess the tree, Little Dormi needs your help to devise a winning strategy!

Note that the game master creates the tree before the game starts, and does not change it during the game.

Input
The first line of input contains the integer n (2≤n≤2000), the number of nodes in the tree.

You will then begin interaction.

Output
When your program has found the tree, first output a line consisting of a single "!" followed by n−1 lines each with two space separated integers a and b, denoting an edge connecting nodes a and b (1≤a,b≤n). Once you are done, terminate your program normally immediately after flushing the output stream.

You may output the edges in any order and an edge (a,b) is considered the same as an edge (b,a). Answering is not considered as a query.

Interaction
After taking input, you may make at most ⌈n2⌉ queries. Each query is made in the format "? r", where r is an integer 1≤r≤n that denotes the node you want to pick for that query.

You will then receive n space separated integers d1,d2,…,dn, where di is the length of the shortest path from node r to i, followed by a newline.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see documentation for other languages.
If at any point you make an invalid query or try to make more than ⌈n2⌉ queries, the interaction will terminate immediately and you will receive a Wrong Answer verdict.

Hacks

To hack a solution, use the following format.

The first line contains the integer n (2≤n≤2000).

The next n−1 lines contain two integers u and v (1≤u,v≤n) denoting an edge between u and v (u≠v). These n−1 edges must form a tree.

Examples
inputCopy
4

0 1 2 2

1 0 1 1
outputCopy
? 1

? 2

!
4 2
1 2
2 3
inputCopy
5

2 2 1 1 0
outputCopy
? 5

!
4 5
3 5
2 4
1 3

*/
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void askQuery(int v,vector<pii> &edges,int n){
	cout<<"? "<<v<<endl;
	vi arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		if(i > 1 && arr[i] == 1){
			edges.push_back({i,v});
		}
	}
}
void takeEdges(vector<int> &arr,vector<pii> &edges,int n){
	for(int x:arr){
		askQuery(x,edges,n);
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> edges;
	vector<int> black,white;
	cout<<"? "<<1<<endl;
	vi dist(n+1);
	for(int i=1;i<=n;i++){
		cin >> dist[i];
	}
	for(int i=2;i<=n;i++){
		if(dist[i] == 1){
			edges.push_back({1,i});
		}
		if(dist[i] % 2 == 0){
			black.push_back(i);
		}else{
			white.push_back(i);
		}
	}
	if(black.size() <= white.size()){
		takeEdges(black,edges,n);
	}else{
		takeEdges(white,edges,n);
	}
	cout<<"! "<<"\n";
	for(pii x:edges){
		cout<<x.ff<<" "<<x.ss<<"\n";
	}
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