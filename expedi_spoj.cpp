/*
EXPEDI - Expedition
#greedy
A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels.

To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).

The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).

Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.

Input
The first line of the input contains an integer t representing the number of test cases. Then t test cases follow. Each test case has the follwing form:

Line 1: A single integer, N
Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
Line N+2: Two space-separated integers, L and P
Output
For each test case, output a single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.

Example
Input:
1
4
4 4
5 2
11 5
15 10
25 10

Output:
2

Input details
The truck is 25 units away from the town; the truck has 10 units
of fuel.  Along the road, there are 4 fuel stops at distances 4,
5, 11, and 15 from the town (so these are initially at distances
21, 20, 14, and 10 from the truck).  These fuel stops can supply
up to 4, 2, 5, and 10 units of fuel, respectively.

Output details:
Drive 10 units, stop to acquire 10 more units of fuel, drive 4 more
units, stop to acquire 5 more units of fuel, then drive to the town.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<pii> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i].first >> arr[i].second;
		}
		int distance,fuel_cap;
		cin >>distance >>fuel_cap;
		for(int i=0;i<n;i++){
			arr[i].first = distance - arr[i].first;
		}
		sort(arr.begin(),arr.end());
		priority_queue<int> pq;
		bool flag = true;
		int x = 0,prev_co = 0;
		int ans = 0;
		while(x < n){
			if(fuel_cap + prev_co >= arr[x].first){
				fuel_cap -= (arr[x].first - prev_co);
				pq.push(arr[x].second);
				prev_co = arr[x].first;
				x++;
			}else{
				if(pq.empty()){
					flag = false;
					break;
				}
				fuel_cap += pq.top();
				pq.pop();
				ans++;
			}
		}
		if(!flag){
			cout << -1 <<"\n";
			continue;
		}
		distance -= (arr.back()).first;
		if(fuel_cap >= distance){
			cout << ans <<'\n';
		}else{
			while(fuel_cap < distance){
				if(pq.empty()){
					flag = false;
					break;
				}
				fuel_cap += pq.top();
				pq.pop();
				ans++;
			}
			if(!flag){
				cout << -1 <<"\n";
			}else{
				cout << ans <<"\n";
			}
		}

	}
	return 0;
}