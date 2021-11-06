/*https://practice.geeksforgeeks.org/problems/word-boggle/0
Word Boggle Submissions: 30731   Accuracy: 17.28%   Difficulty: Medium   Marks: 4
Associated Course(s):   Interview Preparation   Geeks Classes More

Problems
Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer x denoting the no of words in the dictionary. Then in the next line are x space separated strings denoting the contents of the dictinory. In the next line are two integers N and M denoting the size of the boggle. The last line of each test case contains NxM space separated values of the boggle.

Output:
For each test case in a new line print the space separated sorted distinct words of the dictionary which could be formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ

** For More Input/Output Examples Use 'Expected Output' option **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
struct trieNode{
	char data;
	unordered_map<char,trieNode*> children;
	bool terminal;
	trieNode(char ch){
		data = ch;
		terminal = false;
	}
};
void addWord(trieNode* root,string &word){
	trieNode* curr = root;
	for(char c:word){
		if(curr->children.count(c) == 0){
			trieNode* temp = new trieNode(c);
			curr->children[c] = temp;
		}
		curr = curr->children[c];
	}
	curr->terminal = true;
}
bool isSafe(int x,int y,int m,int n,vector<vector<bool>> &visited,vector<vector<char>> &board,char ch){
	return ((x>=0) && (y>=0) && (x<m) && (y<n) && !visited[x][y] && board[x][y] == ch);
}
void searchWord(int i,int j,int m,int n,trieNode* curr,vector<vector<char>> &board,vector<vector<bool>> &visited,set<string> &solution,string &s){
	if(curr->terminal == true){
		solution.insert(s);
	}
	visited[i][j] = true;
	for(auto it=curr->children.begin();it!=curr->children.end();++it){
		char ch = it->first;
		for(int idx=0;idx<8;idx++){
			int new_x = i+dx[idx],new_y = j+dy[idx];
			if(isSafe(new_x,new_y,m,n,visited,board,ch)){
				s.push_back(ch);
				searchWord(new_x,new_y,m,n,curr->children[ch],board,visited,solution,s);
				s.pop_back();
			}
		}
	}
	visited[i][j] = false;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int size;
		cin >> size;
		trieNode* root = new trieNode('\0');
		unordered_set<char> starts_with;
		for (int i = 0; i < size; i++) {
			string word;
			cin>>word;
			addWord(root,word);
			starts_with.insert(word[0]);
		}
		int m, n;
		cin >> m >> n;
		vector<vector<char>> board(m,vector<char>(n));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>board[i][j];
			}
		}
		set<string> solution;
		vector<vector<bool>> visited(m,vector<bool>(n,false));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(starts_with.count(board[i][j])){
					string s;
					s.push_back(board[i][j]);
					searchWord(i,j,m,n,root->children[board[i][j]],board,visited,solution,s);
					s.pop_back();
				}
			}
		}
		if(solution.size() == 0){
			cout<<-1<<endl;
		}else{
			for(string x:solution){
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}