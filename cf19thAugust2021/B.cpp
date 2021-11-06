#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(s[0] == '?'){
		string copy1 = s,copy2 = s;
		copy1[0] = 'B';
		copy2[0] = 'R';
		int op1 = 0,op2 = 0;
		for(int i=1;i<n;i++){
			if(copy1[i] == '?'){
				if(copy1[i-1] == 'B'){
					copy1[i] = 'R';
				}else if(copy1[i-1] == 'R'){
					copy1[i] = 'B';
				}
			}
			if(copy1[i] == copy1[i-1]){
				op1++;
			}
		}
		for(int i=1;i<n;i++){
			if(copy2[i] == '?'){
				if(copy2[i-1] == 'B'){
					copy2[i] = 'R';
				}else if(copy2[i-1] == 'R'){
					copy2[i] = 'B';
				}
			}
			if(copy2[i] == copy2[i-1]){
				op2++;
			}
		}
		if(op1 < op2){
			cout << copy1 << "\n";
		}else{
			cout << copy2 << "\n";
		}

	}else{
		for(int i=1;i<n;i++){
			if(s[i] == '?'){
				if(s[i-1] == 'B'){
					s[i] = 'R';
				}else if(s[i-1] == 'R'){
					s[i] = 'B';
				}
			}
		}
		cout << s << "\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}