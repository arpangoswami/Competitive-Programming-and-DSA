#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
int32_t main(int32_t argc, char const* argv[]) {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		cout << "Case #" << t << ": ";
		int n,k,w;
		cin >> n >> k >> w;
		vector<int> length(n+1);
		for(int i=1;i<=k;i++){
			cin >> length[i];
		}
		int al,bl,cl,dl;
		cin >> al >> bl >> cl >> dl; 
		for(int i=k+1;i<=n;i++){
			length[i] = (al * length[i-2] + bl * length[i-1] + cl) % dl;
		}
		vector<int> height(n+1);
		for(int i=1;i<=k;i++){
			cin >> height[i];
		}
		int ah,bh,ch,dh;
		cin >> ah >> bh >> ch >> dh;
		for(int i=k+1;i<=n;i++){
			height[i] = (ah * height[i-2] + bh * height[i-1] + ch) % dh;
		}
		int lastHouseEnd = 0;
		int lastHouseHeight = 0;
		int cum_sum_per = 0;
		int lastPeri = 0;
		int ans = 1;
		for(int i=1;i<=n;i++){
			if(length[i] > lastHouseEnd){
				//doesn't merge
				int per_curr = 2*(w + height[i]);
				lastHouseHeight = height[i];
				lastHouseEnd = length[i] + w;
				cum_sum_per += per_curr;
				ans *= cum_sum_per;
				ans%=mod;
				lastPeri = per_curr;
			}else{
				//merges
				int extra_perimeter = 2*(length[i]+w-lastHouseEnd) + height[i] + abs(lastHouseHeight-height[i]) - lastHouseHeight;
				cout<<"extra_perimeter: "<<extra_perimeter<<"\n";
				lastHouseHeight = height[i];
				lastHouseEnd = length[i] + w;
				lastPeri += extra_perimeter;
				cum_sum_per += extra_perimeter;
				ans *= cum_sum_per;
				ans %= mod;
			}
			cout<<"cum_sum_per: "<<cum_sum_per<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}