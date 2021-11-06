#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct schedule{
	int arrive;
	int depart;
	int index;
	int room;
	schedule():arrive(-1),depart(-1),index(-1),room(-1){}
	schedule(int arr,int dep,int idx,int r): arrive(arr),depart(dep),index(idx),room(r){}
};
struct cmp{
	bool operator()(schedule &s1,schedule &s2){
		return s1.depart > s2.depart;
	}
};
bool compare(schedule &s1,schedule &s2){
	return s1.arrive < s2.arrive;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<schedule> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].arrive >> arr[i].depart;
		arr[i].index = i;
	}
	sort(arr.begin(),arr.end(),compare);
	int maxm = 1;
	vector<int> room(n);
	priority_queue<schedule,vector<schedule>,cmp> pq;
	room[arr[0].index] = 1;
	arr[0].room = 1;
	pq.push(arr[0]);
	for(int i=1;i<n;i++){
		schedule temp = pq.top();
		if(arr[i].arrive <= temp.depart){
			arr[i].room = pq.size() + 1;
			room[arr[i].index] = arr[i].room;
			pq.push(arr[i]);
		}else{
			pq.pop();
			arr[i].room = temp.room;
			room[arr[i].index] = arr[i].room;
			pq.push(arr[i]);
		}
		curr = pq.size();
		maxm = max(curr,maxm);
	}
	cout<<maxm<<"\n";
	for(int x:room){
		cout<<x<<" ";
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