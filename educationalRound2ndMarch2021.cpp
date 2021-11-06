#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check1(string &s,char c1,char c2,char c3){
	int cnt = 0;
	for(char c:s){
		if(c == c1 || c == c2){
			cnt++;
		}else{
			if(cnt == 0){
				return false;
			}
			cnt--;
		}
	}
	return cnt == 0;
}
bool check2(string &s,char c1,char c2,char c3){
	int cnt = 0;
	for(char c:s){
		if(c == c1){
			cnt++;
		}else{
			if(cnt == 0){
				return false;
			}
			cnt--;
		}
	}
	return cnt == 0;
}
void solveQuestion(){
	string s;
	cin >> s;
	//2 left 1 right
	if(check1(s,'A','B','C') || check1(s,'A','C','B') || check1(s,'B','C','A')){
		cout<<"YES"<<'\n';
		return;
	}
	//1 left 2 right
	if(check2(s,'A','B','C') || check2(s,'C','A','B') || check2(s,'B','C','A')){
		cout<<"YES"<<'\n';
		return;
	}
	cout<<"NO"<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}