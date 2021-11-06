#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct myCmp{
	bool operator()(pii &p1,pii &p2){
		int dist1 = (p1.second - p1.first + 1);
		int dist2 = (p2.second - p2.first + 1);
		if(dist1<dist2){
			return true;
		}
		else if(dist1>dist2){
			return false;
		}
		else{
			if(p1.first<p2.first){
				return false;
			}
			return true;
		}
	}
};
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int op;
		cin>>op;
		vector<int>arr(op,0);
		pii ps = make_pair(0,op-1);
		priority_queue<pii,vector<pii>,myCmp> pq;
		pq.push(ps);
		int toPut = 1;
		while(!pq.empty()){
			pii temp = pq.top();
			pq.pop();
			int l = temp.first;
			int h = temp.second;
			int idx = l + (h - l)/2;
			arr[idx] = toPut;
			int fl = l,fh = idx-1,sl = idx+1,sh = h;
			if(fl<=fh){
				pq.push({fl,fh});
			}
			if(sl<=sh){
				pq.push({sl,sh});
			}
			toPut++;
		}
		for(int i=0;i<arr.size();i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}