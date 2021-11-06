#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int calDist(int x_co,int y_co,vector<pii> &arr,int n){
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += (abs(arr[i].first - x_co) + abs(arr[i].second - y_co));
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	int xSum = 0,ySum = 0;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	//int xSum = 0,ySum = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			xSum += (abs(arr[i].first - arr[j].first));
			ySum += abs(arr[i].second - arr[j].second);
		}
	}
	if(xSum % n == 0 && ySum % n == 0){
		set<pii> st;
		int xC = xSum/n,yC = ySum/n;
		int minDist = calDist(xC,yC,arr,n);
		st.insert({xC,yC});
		for(int i=0;i<n;i++){
			int dist = calDist(arr[i].first,arr[i].second,arr,n);
			if(dist == minDist && st.count(arr[i]) == 0){
				st.insert(arr[i]);
			}
		}
		cout<<st.size()<<'\n';
	}else if(xSum % n != 0 && ySum % n == 0){
		set<pii> st;
		int xC1 = xSum/n,xC2 = (xSum+(n-1))/n,yC = ySum/n;
		int minDist = calDist(xC1,yC,arr,n);
		minDist = min(minDist,calDist(xC2,yC,arr,n));
		if(minDist == calDist(xC1,yC,arr,n)){
			st.insert({xC1,yC});
		}
		if(minDist == calDist(xC2,yC,arr,n))
			st.insert({xC2,yC});


		for(int i=0;i<n;i++){
			int dist = calDist(arr[i].first,arr[i].second,arr,n);
			if(dist == minDist && st.count(arr[i]) == 0){
				st.insert(arr[i]);
			}
		}
		cout<<st.size()<<'\n';
	}else if(xSum % n == 0 && ySum % n != 0){
		set<pii> st;
		int yC1 = ySum/n,yC2 = (ySum+(n-1))/n,xC = xSum/n;
		int minDist = calDist(xC,yC1,arr,n);
		minDist = min(minDist,calDist(xC,yC2,arr,n));
		if(calDist(xC,yC1,arr,n) == minDist){
			st.insert({xC,yC1});
		}
		if(calDist(xC,yC2,arr,n) == minDist){
			st.insert({xC,yC2});
		}
		for(int i=0;i<n;i++){
			int dist = calDist(arr[i].first,arr[i].second,arr,n);
			if(dist == minDist && st.count(arr[i]) == 0){
				st.insert(arr[i]);
			}
		}
		cout<<st.size()<<'\n';
	}else if(xSum % n != 0 && ySum % n != 0){
		set<pii> st;
		int yC1 = ySum/n,xC1 = xSum/n,yC2 = (ySum + (n-1))/n,xC2 = (xSum + (n-1))/n;
		int minDist = calDist(xC1,yC1,arr,n);
		minDist = min(minDist,calDist(xC1,yC2,arr,n));
		minDist = min(minDist,calDist(xC2,yC1,arr,n));
		minDist = min(minDist,calDist(xC2,yC2,arr,n));
		if(minDist == calDist(xC1,yC1,arr,n))
			st.insert({xC1,yC1});
		if(minDist == calDist(xC1,yC2,arr,n))
			st.insert({xC1,yC2});
		if(minDist == calDist(xC2,yC1,arr,n))
			st.insert({xC2,yC1});
		if(minDist == calDist(xC2,yC2,arr,n))
			st.insert({xC2,yC2});
		for(int i=0;i<n;i++){
			int dist = calDist(arr[i].first,arr[i].second,arr,n);
			if(dist == minDist && st.count(arr[i]) == 0){
				st.insert(arr[i]);
			}
		}
		//cout<<"yolo"<<'\n';
		for(pii x:st){
			cout<<x.first<<" "<<x.second<<'\n';
		}
		cout<<st.size()<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}