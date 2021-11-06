#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool isPal(string &s){
	int i=0,j = (int)s.size()-1;
	while(i < j){
		if(s[i] != s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
void solveQuestion(){
	int a,b;
	cin >> a >> b;
	string s;
	cin >> s;
	int q = 0,ones = 0,zeros = 0,n = s.size();
	for(char c:s){
		if(c == '?'){
			q++;
		}else if(c == '1'){
			ones++;
		}else if(c == '0'){
			zeros++;
		}
	}
	if(a+b != n){
		cout<<-1<<'\n';
	}else{
		int rem[2] = {0};
		rem[0] = a - zeros,rem[1] = b-ones;
		for(int i=0;i<(n/2);i++){
			if(s[i] == '?' && s[n-1-i] != '?'){
				int num = s[n-1-i] - '0';
				if(rem[num] == 0){
					cout<<-1<<'\n';
					return;
				}else{
					s[i] = num+'0';
					rem[num]--;
				}
			}else if(s[i] != '?' && s[n-1-i] == '?'){
				int num = s[i] - '0';
				if(rem[num] == 0){
					cout<<-1<<'\n';
					return;
				}else{
					s[n-1-i] = num+'0';
					rem[num]--;
				}
			}
		}
		for(int i=0;i<(n/2);i++){
			if(s[i] == '?'){
				if(rem[0] >= 2){
					s[i] = '0';
					s[n-1-i] = '0';
					rem[0] -= 2;
				}else if(rem[1] >= 2){
					s[i] = '1';
					s[n-1-i] = '1';
					rem[1] -= 2;
				}else{
					cout<<-1<<'\n';
					return;
				}
			}
		}
		if(n % 2 && s[n/2] == '?'){
			if(rem[0] == 1){
				s[n/2] = '0';
				rem[0]--;
			}else if(rem[1] == 1){
				s[n/2] = '1';
				rem[1]--;
			}else{
				cout<<-1<<'\n';
				return;
			}
		}
		if(isPal(s) && rem[0] == 0 && rem[1] == 0){
			cout<<s<<'\n';
			return;
		}
		cout<<-1<<'\n';
	}
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