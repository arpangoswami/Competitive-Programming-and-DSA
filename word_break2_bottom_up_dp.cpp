#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<string> wordBreak(string s,const vector<string> &wordDict,map<string,vector<string>>&mp){
	if(mp.count(s)){
		return mp[s];
	}
	if(s.size() == 0){
		return {""};
	}
	vector<string> subProblem;
	vector<string> thisProblem;
	for(string partition:wordDict){
		if(s.substr(0,partition.size()) == partition){
			subProblem = wordBreak(s.substr(partition.size()),wordDict,mp);
			for(string word:subProblem){
				string temp = partition;
				temp = temp + " " + word;
				if(temp[temp.size()-1] == ' '){
					temp.pop_back();
				}
				thisProblem.push_back(temp);
			}
		}
	}
	return mp[s] = thisProblem;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<string> wordDict(n);
		for(int i=0;i<n;++i){
			cin >> wordDict[i];
		}
		string s;
		cin >> s;
		map<string,vector<string>>mp;
		vector<string> solution = wordBreak(s,wordDict,mp);
		sort(solution.begin(),solution.end());
		for(string k:solution){
			cout<<"("<<k<<")";
		}
		cout<<"\n";
	}
	return 0;
}