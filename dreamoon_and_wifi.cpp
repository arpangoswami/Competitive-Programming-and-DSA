#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
void allProbs(string b,int m,string &candidate,vector<string> &allPossible){
	if(m == 0){
		allPossible.push_back(candidate);
		return;
	}
	if(b[m-1] == '+'){
		candidate.push_back('+');
		allProbs(b,m-1,candidate,allPossible);
		candidate.pop_back();
	}else if(b[m-1] == '-'){
		candidate.push_back('-');
		allProbs(b,m-1,candidate,allPossible);
		candidate.pop_back();
	}else{
		candidate.push_back('+');
		allProbs(b,m-1,candidate,allPossible);
		candidate.pop_back();
		candidate.push_back('-');
		allProbs(b,m-1,candidate,allPossible);
		candidate.pop_back();
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string a,b;
	cin>>a>>b;
	int correct = 0;
	for(char c:a){
		if(c == '+'){
			correct++;
		}else{
			correct--;
		}
	}
	string candidate;
	vector<string> allPossible;
	allProbs(b,b.size(),candidate,allPossible);
	int ans = 0;
	for(string x:allPossible){
		int pos = 0;
		for(char c:x){
			if(c == '+'){
				pos++;
			}else{
				pos--;
			}
		}
		if(pos == correct){
			ans++;
		}
	}
	cout<<fixed<<setprecision(12)<<(double)ans/(double)allPossible.size()<<endl;
	return 0;
}