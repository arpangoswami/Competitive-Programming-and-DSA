#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
struct treeNode{
	int val;
	treeNode* left;
	treeNode* right;
	treeNode(int n){
		val = n;
		left = nullptr;
		right = nullptr;
	}
};
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while(cin>>n){
		string s;
		cin>>s;
		vector<treeNode*> nodes;
		s.erase(std::remove_if (s.begin(), s.end(), ::isspace), s.end());
		cout<<s<<endl;
	}
	return 0;
}