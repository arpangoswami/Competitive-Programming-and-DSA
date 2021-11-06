/*
Company Queries I
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.

Your task is to process q queries of the form: who is employee x's boss k levels higher up in the hierarchy?

Input

The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,…,n, and employee 1 is the general director.

The next line has n−1 integers e2,e3,…,en: for each employee 2,3,…,n their boss.

Finally, there are q lines describing the queries. Each line has two integers x and k: who is employee x's boss k levels higher up?

Output

Print the answer for each query. If such a boss does not exist, print −1.

Constraints
1≤n,q≤2⋅105
1≤ei≤i−1
1≤x≤n
1≤k≤n
Example

Input:
5 3
1 1 3 3
4 1
4 2
4 3

Output:
3
1
-1
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[200001];
int up[200001][20];
void binary_lifting(int src,int par){
	up[src][0] = par;
	for(int i=1;i<20;i++){
		if(up[src][i-1]!=-1){
			up[src][i] = up[up[src][i-1]][i-1];
		}else{
			up[src][i] = -1;
		}
	}
	for(int child:adj_list[src]){
		if(child!=par){
			binary_lifting(child,src);
		}
	}
}

int lift_node(int node,int jump_req){
	for(int i=19;i>=0;i--){
		if(node == -1 || jump_req == 0){
			break;
		}
		if((1 << i) <= jump_req){
			jump_req -= (1 << i);
			node = up[node][i];
		}
	}
	return node;
}

int main() {
	int n, q;
	cin >> n >> q;
	for(int i=2; i < n + 1; i++)
	{	
		int x;
		cin >> x;
		adj_list[x].push_back(i);
		adj_list[i].push_back(x);
	}
	binary_lifting(1, -1);
	while (q--) {
		int node, k;
		cin >> node >> k;
		cout << lift_node(node, k) << '\n';
	}
	return 0;
}
