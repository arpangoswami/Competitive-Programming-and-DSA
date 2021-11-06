#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int LL;

int main()
{
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; 
	scanf("%d", &t);
	while(t--) {
		int N;
		LL x;
		scanf("%d %lld", &N, &x);

		vector<LL> arr(N);
		LL a;	
		for(auto i = 0; i < N; ++i) {
			scanf("%lld", &arr[i]);
		}
		sort(arr.begin(), arr.end());

		LL lower = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

		LL count = 0;
		for(auto i = lower; i < N; ++i) {
			if(arr[i] > x) {
				while(arr[i] > x) {
	  				x = 2 * x;
	  				count++;
	  			}
    		}
    	  	count++;
			x = 2 * arr[i];
		}
		
		LL ans = lower + count;
        LL ans2 = INT_MAX;
		if(lower > 0 && arr[lower] != x) {
    		count = 0;
    		lower -= 1;
    		for(auto i = lower; i < N; ++i) {
    			if(arr[i] > x) {
    				while(arr[i] > x) {
    	  				x = 2 * x;
    	  				count++;
    	  			}
    			}
    			count++;
    			x = 2 * arr[i];
    		}
    		ans2 = lower + count;
		}
		//cout<<"ans: "<<ans<<" ans2: "<<ans2<<"\n";
		printf("%lld\n", min(ans,ans2));
	}
	return 0;
}