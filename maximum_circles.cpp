#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct circle{
	int start,end;
};
bool compare(circle &C1,circle &C2){
	if(C1.end == C2.end){
		return C1.start < C2.start;
	}
	return C1.end < C2.end;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n;
		cin >> n;
		circle diameter[n];
		for(int i = 0;i<n;i++){
			int x,y;
			cin >> x >> y;
			diameter[i].start = x-y;
			diameter[i].end = x+y;
		}	
		sort(diameter,diameter+n,compare);
		int cnt = 0;
		int curr = diameter[0].end;
		for(int i=1;i<n;i++){
			if(diameter[i].start >= curr){
				curr = diameter[i].end;
			}else{
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}