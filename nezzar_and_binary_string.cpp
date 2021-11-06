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
//Change it according to question
const int doesntEffect = 0;
int SZ;
class seg_tree {
  int n;
  vector <int> tree, lazy;
  public :
    seg_tree(int _n) : n(_n) {
      tree.resize(4 * n + 11, 0);
      lazy.resize(4 * n + 11, 0);
    }
    
    void upd(int n, int s, int e, int i, int x) {
      if (s == e) {
        tree[n] = x;
      } else {
        int m = (s + e) >> 1;
        if (i <= m) {
          upd(n << 1, s, m, i, x);
        } else {
          upd(n << 1 | 1, m + 1, e, i, x);
        }
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
      }
    }
    
    void upd(int i, int x) {
      upd(1, 1, n, i, x);
    }
    
    int get_sum(int n, int s, int e, int l, int r) {
      if (s > e || s > r || e < l)
        return 0;
      if (lazy[n])
        shift(n, s, e);
      if (l <= s && e <= r)
        return tree[n];
      int m = (s + e) >> 1;
      return get_sum(n << 1, s, m, l, r) + get_sum(n << 1 | 1, m + 1, e, l, r);
    }
    
    int get_sum(int l, int r) {
      if (l > r) {
        return 0;
      } else {
        return get_sum(1, 1, n, l, r);
      }
    }
    
    void shift(int n, int s, int e) {
      tree[n] += lazy[n];
      if (s != e) {
        lazy[n << 1] += lazy[n];
        lazy[n << 1 | 1] += lazy[n];
      }
      lazy[n] = 0;
    }
    
    void lazy_upd(int n, int s, int e, int l, int r, int x) {
      if (lazy[n])
        shift(n, s, e);
      if (s > e || s > r || e < l)
        return ;
      if (l <= s && e <= r) {
        lazy[n] = x;
        shift(n, s, e);
        return ;
      }
      int m = (s + e) >> 1;
      lazy_upd(n << 1, s, m, l, r, x);
      lazy_upd(n << 1 | 1, m + 1, e, l, r, x);
      tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
    
    void lazy_upd(int l, int r, int x) {
      lazy_upd(1, 1, n, l, r, x);
    }
    void printTree(){
    	for(int x:tree){
    		cout<<x<<" ";
    	}
    	cout<<"\n";
    }
};
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	string s1,s2;
	cin >> s1 >> s2;
	vector<int> arr1(n),arr2(n);
	for(int i=0;i<n;i++){
		arr1[i] = s1[i] - '0';
		arr2[i] = s2[i] - '0';
	}
	SZ = n;
	seg_tree st(n);
	for(int i=0;i<n;i++){
		st.upd(i+1,arr2[i]);
	}
	st.printTree();
	vector<pii> queries(k);
	for(pii &x:queries){
		cin >> x.ff >> x.ss;
	}
	for(int i=k-1;i>=0;i--){
		int left = queries[i].ff,right = queries[i].ss;
		int sum = st.get_sum(left,right);
		int length = (right - left + 1);
		if(sum * 2 == length){
			cout<<"NO\n";
			return;
		}else if(sum * 2 < length){
			st.lazy_upd(left,right,0);
		}else{
			st.lazy_upd(left,right,1);
		}
		st.printTree();
	}
	for(int i=0;i<n;i++){
		if(arr1[i] != st.get_sum(i+1,i+1)){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
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