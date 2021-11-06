#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int moves = 0;
		int curr = 0;
		for(int i=0;i<n;i++){
			if(s[i] == '('){
				curr++;
			}else{
				if(curr == 0){
					moves++;
				}else{
					curr--;
				}
			}
		}
		cout<<moves<<"\n";
	}
	return 0;
}