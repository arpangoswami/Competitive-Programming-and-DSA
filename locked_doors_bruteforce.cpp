#include <bits/stdc++.h>
#define int long long
using namespace std;
struct room{
	int room_num;
	int left;
	int right;
	room(){
		room_num = 0;
		left = 1e7;
		right = 1e7;
	}
	room(int rn,int l,int r){
		room_num = rn;
		left = l;
		right = r;
	}
};
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int n,q;
		cin>>n>>q;
		vector<room> arr(n+2);
		arr[1].room_num = 1;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			arr[i].room_num = i;
			arr[i-1].right = x;
			arr[i].left = x;
		}
		vector<int> solution;
		for(int i=1;i<=q;i++){
			int start,visit;
			cin>>start>>visit;
			int room = start;
			int left_room = room-1;
			int right_room = room+1;
			int left_difficulty = arr[room].left;
			int right_difficulty = arr[room].right;
			while(visit > 1){
				if(left_difficulty < right_difficulty){
					room = left_room;
					left_room = room-1;
					left_difficulty = arr[room].left;
				}else if(left_difficulty > right_difficulty){
					room = right_room;
					right_room = room+1;
					right_difficulty = arr[room].right;
				}
				visit--;
			}
			solution.push_back(room);
		}
		cout<<"Case #"<<t<<": ";
		for(int x:solution){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}