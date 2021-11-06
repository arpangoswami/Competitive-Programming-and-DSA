#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main(int argc, char const *argv[])
{
	int n,queries;
	cin >> n >> queries;
	queue<int> q;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	ordered_set exited;
	int ans = 0;
	while(queries--){
		int type,x;
		cin >> type >> x;
		if(type == 1){
			while(!q.empty() && exited.find(x) != exited.end()){
				q.pop();
			}
			if(!q.empty()){
				exited.insert(q.front());
				q.pop();
			}
		}else if(type == 2){
			exited.insert(x);
		}else if(type == 3){
			ans += (x - exited.order_of_key(x));
		}
	}
	cout<<ans<<"\n";
	return 0;
}