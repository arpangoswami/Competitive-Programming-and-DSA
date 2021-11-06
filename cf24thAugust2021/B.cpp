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
bool check(int sum,int diff){
	if(sum % 2 != diff % 2 || (sum < diff)){
		return false;
	}
	return true;
}
void solveQuestion(){
	int a,b;
	cin >> a >> b;
	if(a > b){
		swap(a,b);
	}
	int diff1 = (b-a)/2,diff2 = (b-a+1)/2;
	//cout<<diff1<<" "<<diff2<<endl;
	set<int> st;
	for(int i=0;i<=(a+b)/2;i++){
		if(check(i,diff1)){
			st.insert(i);
			st.insert(a+b-i);
		}else if(check(i,diff2)){
			st.insert(i);
			st.insert(a+b-i);
		}
	}
	cout<<st.size()<<"\n";
	for(int x:st){
		cout<<x<<" ";
	}
	cout<<"\n";
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