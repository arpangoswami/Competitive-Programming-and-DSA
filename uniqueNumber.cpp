#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	if(n > 45){
		cout<<-1<<'\n';
	}else{
		if(n == 45){
			cout<<"123456789"<<'\n';
		}else if(n <= 9){
			cout<<n<<'\n';
		}else{
			set<int,greater<int>> st;
			for(int i=1;i<=9;i++){
				st.insert(i);
			}
			vector<int> arr;
			while(n > 0){
				if(n < *(st.begin())){
					arr.push_back(n);
					n = 0;
				}else{
					auto it = st.begin();
					arr.push_back(*it);
					n -= *it;
					st.erase(it);
				}
			}
			reverse(arr.begin(),arr.end());
			for(int x:arr){
				cout<<x;
			}
			cout<<'\n';
		}
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}