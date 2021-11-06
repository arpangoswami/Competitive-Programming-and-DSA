#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3;
vector<bool> available;
vector<int> val;
vector<char> present;
int n;
bool solve(int i){
	if(i == n){
		int n1 = 0,n2 = 0,n3 = 0;
		for(char c:s1){
			n1 = n1*10 + val[c-'a'];
		}
		for(char c:s2){
			n2 = n2*10 + val[c-'a'];
		}
		for(char c:s3){
			n3 = n3*10 + val[c-'a'];
		}
		if(n1 + n2 == n3 && val[s1[0]-'a']!=0 && val[s2[0]-'a']!=0 && val[s3[0]-'a']!=0){
			for(char c:s1){
				cout<<val[c-'a'];
			}
			cout<<'\n';
			for(char c:s2){
				cout<<val[c-'a'];
			}
			cout<<'\n';
			for(char c:s3){
				cout<<val[c-'a'];
			}
			return true;
		}
		return false;
	}
	for(int num=0;num<=9;num++){
		if(!available[num]){
			continue;
		}
		available[num] = false;
		val[present[i]-'a'] = num;
		bool f = solve(i+1);
		if(f){
			return true;
		}
		available[num] = true;
		val[present[i] - 'a'] = -1;
	}
	return false;
}
void solveQuestion(){
	cin >> s1 >> s2 >> s3;
	set<char> letters;
	for(char c:s1){
		letters.insert(c);
	}
	for(char c:s2){
		letters.insert(c);
	}
	for(char c:s3){
		letters.insert(c);
	}
	if(letters.size() > 10){
		cout<<"UNSOLVABLE";
		return;
	}
	present.clear();
	for(char c:letters){
		present.push_back(c);
	}
	n = present.size();
	
	available.resize(10);
	val.resize(26);
	for(int i=0;i<10;i++){
		available[i] = true;
	}
	for(int i=0;i<26;i++){
		val[i] = -1;
	}
	bool f = solve(0);
	if(!f){
		cout<<"UNSOLVABLE";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}