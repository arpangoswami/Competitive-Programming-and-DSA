/*
D. Minimal Height Tree
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Monocarp had a tree which consisted of n vertices and was rooted at vertex 1. He decided to study BFS (Breadth-first search), so he ran BFS on his tree, starting from the root. BFS can be described by the following pseudocode:

a = [] # the order in which vertices were processed
q = Queue()
q.put(1) # place the root at the end of the queue
while not q.empty():
    k = q.pop() # retrieve the first vertex from the queue
    a.append(k) # append k to the end of the sequence in which vertices were visited
    for y in g[k]: # g[k] is the list of all children of vertex k, sorted in ascending order
        q.put(y)
Monocarp was fascinated by BFS so much that, in the end, he lost his tree. Fortunately, he still has a sequence of vertices, in which order vertices were visited by the BFS algorithm (the array a from the pseudocode). Monocarp knows that each vertex was visited exactly once (since they were put and taken from the queue exactly once). Also, he knows that all children of each vertex were viewed in ascending order.

Monocarp knows that there are many trees (in the general case) with the same visiting order a, so he doesn't hope to restore his tree. Monocarp is okay with any tree that has minimum height.

The height of a tree is the maximum depth of the tree's vertices, and the depth of a vertex is the number of edges in the path from the root to it. For example, the depth of vertex 1 is 0, since it's the root, and the depth of all root's children are 1.

Help Monocarp to find any tree with given visiting order a and minimum height.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains a single integer n (2≤n≤2⋅105) — the number of vertices in the tree.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n; ai≠aj; a1=1) — the order in which the vertices were visited by the BFS algorithm.

It's guaranteed that the total sum of n over test cases doesn't exceed 2⋅105.

Output
For each test case print the minimum possible height of a tree with the given visiting order a.

Example
inputCopy
3
4
1 4 3 2
2
1 2
3
1 2 3
outputCopy
3
1
1
Note
In the first test case, there is only one tree with the given visiting order:
			1
			/
			4
			/
			3
			/
			2


In the second test case, there is only one tree with the given visiting order as well:
1
/
2


In the third test case, an optimal tree with the given visiting order is shown below:
1
/
2
/
3

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	queue<int> Q1;
	queue<int> Q2;
	int height = 1;
	for(int i=1;i<n;i++){
		if(arr[i] < arr[i-1]){
			if(Q1.empty()){
				Q1.swap(Q2);
				height++;
			}
			Q1.pop();
			Q2.push(arr[i]);
		}else{
			Q2.push(arr[i]);
		}
	}
	cout<<height<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}