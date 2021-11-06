#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
void solveQ(){
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr){
        cin >> i;
    }
    map<int,vector<int>> position;
    map<int,vector<int>> suffix;
    for(int i=0;i<n;i++){
        position[arr[i]].push_back(i);
        suffix[arr[i]].push_back(n-i);
    }
    for(auto &it:suffix){
        auto &v = it.second;
        int N = v.size();
        for(int i=N-2;i>=0;i--){
            v[i]+=v[i+1];
        }
    }
    int ans = 0;
    for(auto &it:position){
        int value = it.first;
        auto v = it.second;
        int N = v.size();
        if(v.size() >= 2){
            for(int i=0;i<(N-1);i++){
                
                ans += (v[i]+1) * suffix[value][i+1];
            }
        }
    }
    cout<<ans<<"\n";
}
int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    solveQ();
	}
	return 0;
}
