#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<string> extractWords(string s){
    vector<string> temp;
    string word;
    for(char c:s){
        if(c == '_'){
            temp.push_back(word);
            word.clear();
        }
        else{
            word.push_back(c);
        }
    }
    if(word.size() > 0){
        temp.push_back(word);
    }
    return temp;
}
struct TrieNode{
	char ch;
	unordered_map<char,TrieNode*> children;
	bool terminal;
	TrieNode(char c){
	    ch = c;
	    terminal = false;
	}
};
struct Order{
    int idx;
    int cnt;
};
void addWord(TrieNode *root,string &s){
    TrieNode *curr = root;
    for(char c:s){
        if(curr->children.count(c) == 0){
            TrieNode *temp = new TrieNode(c);
            curr->children[c] = temp;
        }
        curr = curr->children[c];
    }
    curr->terminal = true;
}
bool hasWord(TrieNode *root,string &s){
    TrieNode *curr = root;
    for(char c:s){
        if(curr->children.count(c) == 0){
            return false;
        }
        curr = curr->children[c];
    }
    return curr->terminal;
}
bool cmp(Order &A,Order &B){
    if(A.cnt == B.cnt){
        return A.idx < B.idx;
    }
    return A.cnt > B.cnt;
}
vector<int> solve(string A, vector<string> &B) {
    vector<string> goodWords = extractWords(A);
    TrieNode *root = new TrieNode('\0');
    for(string x:goodWords){
        addWord(root,x);
    }
    int n = B.size();
    vector<Order> toSort(n);
    for(int i=0;i<n;i++){
        Order tmp;
        tmp.cnt = 0;
        tmp.idx = i;
        vector<string> s1 = extractWords(B[i]);
        for(string x:s1){
            if(hasWord(root,x)){
                tmp.cnt++;
            }
        }
        toSort[i] = tmp;
    }
    sort(toSort.begin(),toSort.end(),cmp);
    vector<int> solution(n);
    int ptr = 0;
    for(Order x:toSort){
        solution[ptr++] = x.idx;
    }
    return solution;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string A = "cool_ice_wifi";
	vector<string> goodWords = extractWords(A);
	vector<string> B = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
	vector<int> sol = solve(A,B);
	for(int x: sol){
		cout<<x<<" ";
	}
	cout<<"\n";
	return 0;
}