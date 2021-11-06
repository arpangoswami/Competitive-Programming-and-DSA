#include <bits/stdc++.h>
#include <cstdlib>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma optimize("O3")
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}

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
    SZ = n;
  }
  void build(vector<int> &a, int v=1, int tl=0, int tr=SZ-1) {
    if (tl == tr) {
        sum[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        sum[v] = combine(sum[v*2] , sum[v*2+1]);
    }
}
  int combine(int A, int B) {
      return gcd(A, B);
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
        pull(node);
      }
    } 
  int query(int lo, int hi, int index = 1, int L = 0, int R = SZ-1) {
      push(index, L, R);
      if (lo > R || L > hi) return identity;
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
	int n;
	cin >> n;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	if(n == 1){
		cout<<"1\n";
		return;
	}
	vi diff(n-1);
	for(int i=0;i<(n-1);i++){
		diff[i] = abs(arr[i] - arr[i+1]);
	}
	n--;
	segTree st(n);
	for(int i=0;i<n;i++){
		st.pointUpdate(i,diff[i]);
	}
	int left = 0,ans = 0;
	for(int i=0;i<n;i++){
		int g = st.query(left,i);
		if(g != 1){
			ans = max(ans,i-left+1);
		}else{
			while(left <= i && st.query(left,i) == 1){
				left++;
			}
			ans = max(ans,i-left+1);
		}
	}
	cout << ans + 1 << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}