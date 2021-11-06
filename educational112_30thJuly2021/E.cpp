#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int identity = 0;
int SZ;
class segTree{
	int n;
	vector<int> sum;
	vector<int> lazy;
public:
	segTree(int _n){
		n = _n;
		sum.resize(4*n+15,0);
		lazy.resize(4*n+15,0);
	}
	int combine(int A, int B) {
	    return min(A, B);
	}
	 
	int combineUpd(int A, int B) {
	    return A+B;
	}
	void push(int index, int L, int R) {
	    sum[index] = combineUpd(sum[index], lazy[index]);
	    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
	    lazy[index] = identity;
	}
	 
	void pull(int index) {
	    sum[index] = combine(sum[2*index], sum[2*index+1]);
	}
	void pointUpdate(int idx,int value,int node = 1,int L = 0,int R = SZ-1) {
      if (L == R) {
        sum[node] = value;
      } else {
        int M = (L + R) >> 1;
        if (idx <= M) {
          pointUpdate(idx, value, 2*node, L, M);
        } else {
          pointUpdate(idx, value, 2*node + 1, M+1, R);
        }
        pull(index);
      }
    } 
	int query(int lo, int hi, int index = 1, int L = 0, int R = SZ-1) {
	    push(index, L, R);
	    if (lo > R || L > hi) return 1;
	    if (lo <= L && R <= hi) return sum[index];
	 
	    int M = (L+R) / 2;
	    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
	}
	 
	void update(int lo, int hi, int increase, int index = 1, int L = 0, int R = SZ-1) {
	    push(index, L, R);
	    if (hi < L || R < lo) return;
	    if (lo <= L && R <= hi) {
	        lazy[index] = increase;
	        push(index, L, R);
	        return;
	    }
	 
	    int M = (L+R) / 2;
	    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
	    pull(index);
	}
};

void solveQuestion(){
	int n,m;
	cin >> n >> m;
	SZ = m;
	vector<array<int,3>> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	int idx = 0;
	int ans = 1e8;
	sort(arr.begin(),arr.end(),[](auto &v1,auto &v2){
		return v1[2] < v2[2];
	});
	segTree st(m);
	for(int i=0;i<n;i++){
		while(idx < n && st.query(1,m-1) == 0){
			st.update(arr[idx][0],arr[idx][1]-1,1);
			idx++;
		}
		if(st.query(1,m-1) != 0){
			ans = min(ans,arr[idx-1][2] - arr[i][2]);
		}
		st.update(arr[i][0],arr[i][1]-1,-1);
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}