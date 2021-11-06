#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,N;
	cin >> n >> N;
	vi arr(n);
	map<int,int> indexMap;
	vi evenRight;
	vi oddRight;
	vector<char> direction(n);
	for(int i=0;i<n;i++){
		cin  >> arr[i];
		indexMap[arr[i]] = i; 
	}
	set<int> oddLeft,evenLeft;
	for(int i=0;i<n;i++){
		cin >> direction[i];
		if(direction[i] == 'L'){
			if(arr[i] % 2){
				oddLeft.insert(arr[i]);
			}else{
				evenLeft.insert(arr[i]);
			}
		}else{
			if(arr[i] % 2){
				oddRight.push_back(arr[i]);
			}else{
				evenRight.push_back(arr[i]);
			}
		}
	}
	sort(oddRight.begin(),oddRight.end());
	sort(evenRight.begin(),evenRight.end());
	map<int,int> answer;
	for(int i=(int)oddRight.size()-1;i>=0;i--){
		auto it = oddLeft.lower_bound(oddRight[i]);
		if(it == oddLeft.end()){
			continue;
		}else{
			int val = *it;
			oddLeft.erase(it);
			int time = (val - oddRight[i])/2;
			answer[val] = time;
			answer[oddRight[i]] = time;
		}
	}
	for(int i=(int)evenRight.size()-1;i>=0;i--){
		auto it = evenLeft.lower_bound(evenRight[i]);
		if(it == evenLeft.end()){
			continue;
		}else{
			int val = *it;
			evenLeft.erase(it);
			int time = (val - evenRight[i])/2;
			answer[val] = time;
			answer[evenRight[i]] = time;
		}
	}
	vi oddRight2,evenRight2,oddLeft2,evenLeft2;
	for(int x:oddLeft){
		oddLeft2.push_back(x);
	}
	for(int x:evenLeft){
		evenLeft2.push_back(x);
	}
	for(int x:oddRight){
		if(answer.count(x) == 0){
			oddRight2.push_back(x);
		}
	}
	for(int x:evenRight){
		if(answer.count(x) == 0){
			evenRight2.push_back(x);
		}
	}
	reverse(oddLeft2.begin(),oddLeft2.end());
	reverse(evenLeft2.begin(),evenLeft2.end());
	for(int i=(int)oddRight2.size()-1;i>0;i-=2){
		int v1 = oddRight2[i],v2 = oddRight2[i-1];
		answer[v1] = N - (v1 + v2)/2;
		answer[v2] = N - (v1 + v2)/2;
		oddRight2.pop_back();
		oddRight2.pop_back();
	}
	for(int i=(int)evenRight2.size()-1;i>0;i-=2){
		int v1 = evenRight2[i],v2 = evenRight2[i-1];
		answer[v1] = N - (v1 + v2)/2;
		answer[v2] = N - (v1 + v2)/2;
		evenRight2.pop_back();
		evenRight2.pop_back();
	}
	for(int i=(int)oddLeft2.size()-1;i>0;i-=2){
		int v1 = oddLeft2[i],v2 = oddLeft2[i-1];
		answer[v1] = (v1 + v2)/2;
		answer[v2] = (v1 + v2)/2;
		oddLeft2.pop_back();
		oddLeft2.pop_back();
	}
	for(int i=(int)evenLeft2.size()-1;i>0;i-=2){
		int v1 = evenLeft2[i],v2 = evenLeft2[i-1];
		answer[v1] = (v1 + v2)/2;
		answer[v2] = (v1 + v2)/2;
		evenLeft2.pop_back();
		evenLeft2.pop_back();
	}
	if(oddLeft2.size() >= 1 && oddRight2.size() >= 1 && oddRight2[0] > oddLeft2[0]){
		int time1 = oddLeft2[0],time2 = N - oddRight2[0];
		if(time1 > time2){
			int ans = time1 + (N - (time1 - time2))/2;
			answer[oddLeft2[0]] = ans;
			answer[oddRight2[0]] = ans;
		}else{
			int ans = time2 + (N - (time2 - time1))/2;
			answer[oddLeft2[0]] = ans;
			answer[oddRight2[0]] = ans;
		}
	}
	if(evenLeft2.size() >= 1 && evenRight2.size() >= 1 && evenRight2[0] > evenLeft2[0]){
		int time1 = evenLeft2[0],time2 = N - evenRight2[0];
		if(time1 > time2){
			int ans = time1 + (N - (time1 - time2))/2;
			answer[evenLeft2[0]] = ans;
			answer[evenRight2[0]] = ans;
		}else{
			int ans = time2 + (N - (time2 - time1))/2;
			answer[evenLeft2[0]] = ans;
			answer[evenRight2[0]] = ans;
		}
	}
	vi solution(n,-1);
	for(auto it:answer){
		int val = it.first;
		int ans = it.second;
		int idx = indexMap[val];
		solution[idx] = ans;
	}
	for(int x:solution){
		cout<<x<<" ";
	}
	cout<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}