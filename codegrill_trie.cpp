/*
Saath Nibhana Saathiya Problem Code: CGTR03
Add problem to Todo list
Submit (Practice)

 
One day Rashi went to the kitchen. She took out N strings from the cooker and kept the empty cooker on the stove. But Rashi is clever and she has put the entire blame for this on Gopi. To save herself from the false accusations of Rashi, Gopi must answer M queries asked to her. In each of the M queries, she is given an integer K and she needs to tell the number of possible strings which are prefix of at least K strings out of the given N strings. Can you help Gopi to prove her innocence?

Use fast I/O for input and output due to the large size of output files of the problem

Input format:
• The first line contains an integer N, the number of strings

• The next line contains N strings( S1,S2…Sn).

• The third line contains a single integer M i.e. the number of queries.

• The following M lines contains an integer K .

Output format:
Print M lines each containing a single integer where the ith line contains the answer to the ith query asked.

Constraints:-
• 1≤N≤50000
• 1≤Length(Si)≤50000
• 1≤M≤1000000
• 1≤K≤N
• The sum of lengths of the strings for a particular task does not exceed 10^6.

Scoring:-
• Subtask1(30points)
a) 1≤N≤100
b) 1≤Length(Si)≤10
c) 1≤M≤100
• Subtask2(70points)
a) Original Constraints

Sample input:-
5

aws apk awr bft bqs

4

3

2

1

4

Sample Output:-
1

3

11

0

Explanation:-
Strings which are prefix of at least 1 string- a, b ,aw, ap ,bf ,bq ,aws, apk, awr, bft,bqs.

Strings which are prefix of at least 2 strings- a, b, aw.

Strings which are prefix of at least 3 strings- a.

Strings which are prefix of at least 4 strings- No such strings possible(0).
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct trieNode{
	int count;
	char ch;
	bool terminal;
	unordered_map<char,trieNode*> children;
	trieNode(char c){
		ch = c;
		count = 0;
		terminal = false;
	}
};
void addWord(string s,trieNode *root){
	trieNode *curr = root;
	for(char c:s){
		if(curr->children.count(c) == 0){
			curr->children[c] = new trieNode(c);
		}
		curr = curr->children[c];
		curr->count++;
	}
	curr->terminal = true;
}
void searchPrefix(trieNode *root,int req,int &ans){
	for(auto it:root->children){
		if((it.second)->count >= req){
			ans++;
			searchPrefix(it.second,req,ans);
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	trieNode *root = new trieNode('\0');
	for(int i=0;i<n;i++){
		cin >> s;
		addWord(s,root);
	}
	int q;
	cin >> q;
	unordered_map<int,int> mp;
	while(q--){
		int req;
		cin >> req;
		if(mp.count(req) == 0){
			int ans = 0;
			searchPrefix(root,req,ans);
			mp[req] = ans;
		}
		cout<<mp[req]<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}