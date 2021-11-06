// #include <bits/stdc++.h>
// #include <cstdlib>
// #define int long long
// #define ff first
// #define ss second
// #define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int,int> pii;
// typedef vector<pii> vpi;
// typedef long double ld;
// const int MOD = 1e9 + 7;
// const int MOD2 = 998244353;
// int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
// int fermat_inv(int y){return power(y,MOD-2);}
// int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
// const int MX = 2e5;
// void solveQuestion(){
// 	int d,n,k;
// 	cin >> d >> n >> k;
// 	vector<array<int,3>> rides(n);
// 	map<int,vector<int>> startDays;
// 	map<int,vector<int>> endDays;
// 	for(int i=0;i<n;i++){
// 		cin >> rides[i][0] >> rides[i][1] >> rides[i][2];
// 		startDays[rides[i][1]].push_back(i);
// 		endDays[rides[i][2]].push_back(i);
// 	}
// 	if(n >= 10000){
// 		multiset<array<int,3>> mSet;
// 		multiset<array<int,3>> standBy;
// 		int ans = 0,currSum = 0;
// 		for(int i=1;i<=d;i++){
// 			if(startDays.count(i)){
// 				const vector<int> v = startDays[i];
// 				for(int x:v){
// 					mSet.insert(rides[x]);
// 					currSum += rides[x][0];
// 				}
// 			}
// 			if(endDays.count(i-1)){
// 				const vector<int> v = endDays[i-1];
// 				for(int x:v){
// 					array<int,3> ar = rides[x];
// 					if(mSet.count(ar)){
// 						auto it = mSet.find(ar);
// 						currSum -= ar[0];
// 						mSet.erase(it);
// 					}
// 					if(standBy.count(ar)){
// 						standBy.erase(ar);
// 					}
// 				}
// 			}
// 		//either of the two loops will be executed

// 		//can't attend more than k events
// 		//putting in standby as some events might be helpful later on
// 			while(mSet.size() > k){
// 				auto it = mSet.begin();
// 				currSum -= (*it)[0];
// 				mSet.erase(it);
// 				standBy.insert(*it);
// 			}

// 		//when mSet size < k
// 		//taking from standBy
// 			while(!standBy.empty() && mSet.size() < k){
// 				auto it = standBy.end();
// 				--it;
// 				currSum += (*it)[0];
// 				standBy.erase(it);
// 				mSet.insert(*it);
// 			}
// 			ans = max(ans,currSum);
// 		}
// 		cout << ans << "\n";
// 	}else{
// 		int ans = 0;
// 		for(int i=1;i<=d;i++){
// 			vector<int> v;
// 			for(int j=0;j<n;j++){
// 				if(rides[j][1] <= i && rides[j][2] >= i){
// 					v.push_back(rides[j][0]);
// 				}
// 			}
// 			sort(v.begin(),v.end(),greater<int>());
// 			int last = min((int)v.size(),k);
// 			int cs = 0;
// 			for(int j=0;j<last;j++){
// 				cs += v[j];
// 			}
// 			ans = max(ans,cs);
// 		}
// 		cout << ans << "\n";
// 	}
// }
// int32_t main(int32_t argc, char const *argv[])
// {
// 	/* code */
// 	Boost();
	// #ifndef ONLINE_JUDGE

	// freopen("C_tc_1.txt", "r", stdin);

	// freopen("B_output.txt", "w", stdout);

	// #endif
// 	int tt = 1;
// 	cin >> tt;
// 	for(int i=1;i<=tt;i++){
// 		cout<<"Case #"<<i<<": ";
// 		solveQuestion();
// 	}
// 	return 0;
// }
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
const int MX = 2e5;
void solveQuestion(){
	int d,n,k;
	cin >> d >> n >> k;
	vector<array<int,3>> rides(n);
	map<int,vector<int>> startDays;
	map<int,vector<int>> endDays;
	for(int i=0;i<n;i++){
		cin >> rides[i][0] >> rides[i][1] >> rides[i][2];
		startDays[rides[i][1]].push_back(i);
		endDays[rides[i][2]].push_back(i);
	}
	if(n >= 10000){
		multiset<array<int,3>> mSet;
		multiset<array<int,3>> standBy;
		int ans = 0,currSum = 0;
		for(int i=1;i<=d;i++){
			if(startDays.count(i)){
				const vector<int> v = startDays[i];
				for(int x:v){
					mSet.insert(rides[x]);
					currSum += rides[x][0];
				}
			}
			if(endDays.count(i-1)){
				const vector<int> v = endDays[i-1];
				for(int x:v){
					array<int,3> ar = rides[x];
					if(mSet.count(ar)){
						auto it = mSet.find(ar);
						currSum -= ar[0];
						mSet.erase(it);
					}
					if(standBy.count(ar)){
						standBy.erase(ar);
					}
				}
			}
		//either of the two loops will be executed

		//can't attend more than k events
		//putting in standby as some events might be helpful later on
			while(mSet.size() > k){
				auto it = mSet.begin();
				currSum -= (*it)[0];
				mSet.erase(it);
				standBy.insert(*it);
			}

		//when mSet size < k
		//taking from standBy
			while(!standBy.empty() && mSet.size() < k){
				auto it = standBy.end();
				--it;
				currSum += (*it)[0];
				standBy.erase(it);
				mSet.insert(*it);
			}
			ans = max(ans,currSum);
		}
		cout << ans << "\n";
	}else{
		sort(rides.begin(),rides.end(),[](auto &v1,auto &v2){
			return v1[2] < v2[2];
		});
		int left = 0,right = 0,ans = 0;
		for(int i=0;i<n;i++){
			int day = rides[i][2];		
			while(right < n && rides[right][1] <= day){
				right++;
			}
			right--;
			while(left <= right && rides[left][2] < day){
				left++;
			}
			int cs = 0;
			priority_queue<int,vector<int>,greater<int>> pq;
			for(int j=left;j<=right;j++){
				if(pq.size() < k){
					cs += rides[j][0];
					pq.push(rides[j][0]);
				}else if(rides[j][0] >= pq.top()){
					cs -= pq.top();
					pq.pop();
					cs += rides[j][0];
					pq.push(rides[j][0]);
				}
			}
			//cout<<"left: "<<left<<" right: "<<right<<"\n";
			ans = max(ans,cs); 	
		}
		cout << ans << "\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("C_tc_1.txt", "r", stdin);

	freopen("B_output.txt", "w", stdout);

	#endif
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}