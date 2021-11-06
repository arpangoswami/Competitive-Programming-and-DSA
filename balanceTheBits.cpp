#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	string s;	
	cin >> n >> s;
	int ones = 0;
	for(char c:s){
		if(c == '1'){
			ones++;
		}
	}
	if(s[0] == '0' || s[n-1] == '0' || ones % 2 == 1){
		cout<<"NO"<<'\n';
		return;
	}
	cout<<"YES"<<endl;
	//always eager to place closing bracket
	string a,b;
	int open1 = 0,close1 = 0,open2 = 0,close2 = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			if(open1 == close1 || open2 == close2 || (i!=(n-1) && open1-close1 <=1 && open2-close2<=1)){
				//1 as the last character will be closing in both of them
				a.push_back('(');
				b.push_back('(');
				open1++;
				open2++;
			}else{
				a.push_back(')');
				b.push_back(')');
				close1++;
				close2++;
			}
		}else{
			if(open1-close1 > open2-close2){
				a.push_back(')');
				b.push_back('(');
				open2++;
				close1++;
			}else{
				b.push_back(')');
				a.push_back('(');
				open1++;
				close2++;
			}
		}
	}
	cout<<a<<endl<<b<<endl;
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