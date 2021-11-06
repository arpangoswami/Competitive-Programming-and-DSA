/*
DIEHARD - DIE HARD
#dynamic-programming
Problem Statement:



The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live in any of the three places - fire, water and air. After every unit time, you have to change your place of living. For example if you are currently living at fire, you can either step into water or air.

If you step into air, your health increases by 3 and your armor increases by 2

If you step into water, your health decreases by 5 and your armor decreases by 10

If you step into fire, your health decreases by 20 and your armor increases by 5

If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.

Input:

The first line consists of an integer t, the number of test cases. For each test case there will be two positive integers representing the initial health H and initial armor A.


Output:

For each test case find the maximum time you can survive.

 

Note: You can choose any of the 3 places during your first move.

 

Input Constraints:

1 <= t <= 10
1 <= H, A <= 1000

Example:

Sample Input:

3
2 10
4 4
20 8
Sample Output:

1
1
5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[1100][1100][3];
int maxTime(int health,int armor,int state){
	if(health <= 0 || armor <= 0){
		return 0;
	}
	if(dp[health][armor][state]!=-1){
		return dp[health][armor][state];
	}
	if(state == 0){
		return dp[health][armor][state] = 1 + max(maxTime(health-5,armor-10,1),maxTime(health - 20,armor+5,2));
	}else if(state == 1){
		return dp[health][armor][state] = 1 + max(maxTime(health+3,armor+2,0),maxTime(health - 20,armor+5,2));
	}
	return dp[health][armor][state] = 1 + max(maxTime(health-5,armor-10,1),maxTime(health+3,armor+2,0));
}
void solve(){
	int health,armor;
	cin>>health>>armor;
	if(health == 0 || armor == 0){
		cout<<0<<endl;
		return;
	}
	memset(dp,-1,sizeof(dp));
	int time = 0;
	time = max(time,maxTime(health+3,armor+2,0));
	time = max(time,maxTime(health-20,armor+5,2));
	time = max(time,maxTime(health-5,armor-10,1));
	cout<<time<<endl;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	while(test--){	
		solve();
	}
	return 0;
}