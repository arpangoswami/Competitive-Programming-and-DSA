#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	vector<string> arr;
	string s;
	while(cin >> s){
		arr.push_back(s);
	}
	int len = 0;
	string temp = "";
	for(string x:arr){
		len += (int)x.size();
		temp += x;
	}
	int sz = ceil((double)sqrt(len));
	vector<string> words(sz);
	for(int i=0;i<sz;i++){
		string st;
		for(int j=i;j<len;j+=sz){
			st.push_back(temp[j]);
		}
		words[i] = st;
	}
	for(string x:words){
		cout<<x<<" ";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}