#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int begin,end;
		cin >> begin >> end;
		mp[end] = begin;
	}
	vi marks(m);
	for(int &i:marks){
		cin >> i;
	}
	vi solution(m);
	for(int i=0;i<m;i++){
		int markStu = marks[i];
		auto it = mp.lower_bound(markStu);
		if(it == mp.end()){
			it = prev(it);
			solution[i] = (*it).first;
			int end = solution[i]-1;
			int begin = (*it).second;
			mp.erase(it);
			if(begin <= end){
				mp[end] = begin;
			}
			continue;
		}
		int endNext = (*it).first,beginNext = (*it).second;
		if(markStu >= beginNext && markStu <= endNext){
			solution[i] = markStu;
			mp.erase(it);
			if(markStu-1>=beginNext){
				mp[markStu-1] = beginNext;
			}
			if(markStu+1<=endNext){
				mp[endNext] = markStu+1;
			}
			continue;
		}
		if(it == mp.begin()){
			solution[i] = (*it).second;
			int nBegin = solution[i]+1;
			int nEnd = (*it).first;
			mp.erase(it);
			if(nBegin <= nEnd){
				mp[nEnd] = nBegin;
			}
			continue;
		}
		auto it2 = prev(it);
		int prevEnd = (*it2).first,prevBegin = (*it2).second;
		if(markStu < beginNext && markStu > prevEnd){
			int margin = markStu - prevEnd;
			solution[i] = prevEnd;
			if(margin > (beginNext - markStu)){
				solution[i] = beginNext;
				int nBegin = solution[i]+1;
				mp.erase(it);
				if(nBegin <= endNext){
					mp[endNext] = nBegin;
				}
			}else{
				int prevEndNew = solution[i]-1;
				mp.erase(it2);
				if(prevEndNew >= prevBegin){
					mp[prevEndNew] = prevBegin;
				}
			}
		}
	}
	for(int x:solution){
		cout<<x<<" ";
	}
	cout<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}