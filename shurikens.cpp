#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int idx = 0;
	stack<pii> st;
	int minm = 0;
	bool flag = true;
	for(int i=0;i<2*n;i++){
		char c;
		cin >> c;
		if(c == '+'){
			st.push({idx,0});
			idx++;
		}else{
			int num;
			cin >> num;
			if(st.empty()){
				flag = false;
			}else{
				pii temp = st.top();
				st.pop();
				int id = temp.first,val = temp.second;
				if(num < val){
					flag = false;
				}else{
					arr[id] = num;
					if(!st.empty()){
						pii temp = st.top();
						int id = temp.first,val = temp.second;
						if(val < num){
							st.pop();
							st.push({id,num});
						}
					}
				}
			}
		}
	}
	if(flag){
		cout<<"YES"<<"\n";
		for(int x:arr){
			cout<<x<<" ";
		}
	}else{
		cout<<"NO"<<"\n";
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