#include <bits/stdc++.h>
using namespace std;
vector<int> cycle;
int dfs(int v,vector<bool> &visited,vector<bool> &recStack,vector<int> &arr){
	//cout<<v<<'\n';
	if(v == -1){
		cycle.clear();
		return -1e9;
	}
	if(visited[v] && !recStack[v]){
		cycle.clear();
		return -1e9;
	}
	if(visited[v] && recStack[v]){
		int sum = 0;
		for(int i=(int)cycle.size()-1;i>=0;i--){
			sum += cycle[i];
			if(cycle[i] == v){
				break;
			}
		}
		cycle.clear();
		return sum;
	}
	visited[v] = true;
	recStack[v] = true;
	cycle.push_back(v);
	int ans = dfs(arr[v],visited,recStack,arr);
	recStack[v] = false;
	return ans;
}

int solution(vector<int> &arr){
	int n = arr.size();
	vector<bool> visited(n,false);
	vector<bool> recStack(n,false);
	int ans = 0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			int temp = dfs(i,visited,recStack,arr);
			if(temp > ans){
				ans = temp;
				//cout<<"vertex: "<<i<<'\n';
			}
			//ans = max(ans,dfs(i,visited,recStack,arr));
		}
	}
	return ans;
}
int main(int argc,char **argv){
	int testcases;
	cin >> testcases;
	while(testcases--){
		int array_size;
		cin >> array_size;
		vector<int> arr(array_size);
		for(int i=0;i<array_size;i++){
			cin >> arr[i];
		}
		cout << solution(arr) << endl;
	}
}