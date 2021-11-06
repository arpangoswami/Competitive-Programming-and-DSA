#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> oddFirst,evenFirst,oddSecond,evenSecond;
	//first -> +-
	//second -> -+
	//odd -> start from odd i
	//even -> start from even i

	if(n > 1){
		for(int i=0;i<(n-1);i+=2){
			//+-
			if(s[i] == '+' && s[i+1] == '-'){
				evenFirst.push_back(1);
			}else{
				evenFirst.push_back(0);
			}
			//-+
			if(s[i] == '-' && s[i+1] == '+'){
				evenSecond.push_back(1);
			}else{
				evenSecond.push_back(0);
			}
		}
	}
	if(n > 2){
		for(int i=1;i<(n-1);i+=2){
			//+-
			if(s[i] == '+' && s[i+1] == '-'){
				oddFirst.push_back(1);
			}else{
				oddFirst.push_back(0);
			}
			//-+
			if(s[i] == '-' && s[i+1] == '+'){
				oddSecond.push_back(1);
			}else{
				oddSecond.push_back(0);
			}
		}
	}

	// while(oddFirst.size() < n){
	// 	oddFirst.push_back(oddFirst.back());
	// }
	for(int i=1;i<oddFirst.size();i++){
		oddFirst[i] += oddFirst[i-1];
	}
	for(int i=1;i<evenFirst.size();i++){
		evenFirst[i] += evenFirst[i-1];
	}
	for(int i=1;i<oddSecond.size();i++){
		oddSecond[i] += oddSecond[i-1];
	}
	for(int i=1;i<evenSecond.size();i++){
		evenSecond[i] += evenSecond[i-1];
	}
	// for(int x:oddFirst){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	// for(int x:oddSecond){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	while(q--){
		int l,r;
		cin >> l >> r;
		l--;
		r--;
		int len = (r-l+1);
		if(len%2){
			cout<<"1\n";
			continue;
		}
		if(l % 2){
			l/=2;
			r/=2;
			//cout<<"r: "<<r<<" oddFirst.size(): "<<oddFirst.size()<<"\n";
			int oF = oddFirst[r-1];
			if(l > 0){
				oF -= oddFirst[l-1];
			}
			int oS = oddSecond[r-1];
			if(l > 0){
				oS -= oddSecond[l-1];
			}
			//cout<<"oF: "<<oF<<" oS: "<<oS<<"\n";
			int rem = oF - oS;
			if(rem != 0){
				cout<<"2\n";
			}else{
				cout<<"0\n";
			}
		}else{
			l/=2;
			r/=2;
			int eF = evenFirst[r];
			if(l > 0){
				eF -= evenFirst[l-1];
			}
			int eS = evenSecond[r];
			if(l > 0){
				eS -= evenSecond[l-1];
			}
			int rem = eF - eS;
			if(rem != 0){
				cout<<"2\n";
			}else{
				cout<<"0\n";
			}
		}
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