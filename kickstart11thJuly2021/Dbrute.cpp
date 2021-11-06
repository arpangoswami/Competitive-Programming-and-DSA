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
int power(int a, int b){int res=1;a=a;while(b>0){if(b&1){res=(res*a);}a=(a*a);b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
vector<int> BIT;
vector<int> BIT2;
vector<int> BIT3;
vector<int> BIT4;
int P;
int N;
int value(int x){
	int ans = 0;
	while(x > 0 && x%P == 0){
		ans++;
		x /= P;
	}
	return ans;
}
int ansQuery(int idx){
	int ans = 0;
	while(idx > 0){
		ans += BIT[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}
void updateQuery(int idx,int diff){
	for(;idx<=N;idx += (idx & (-idx))){
		BIT[idx] += diff;
	}
}
int ansQuery2(int idx){
	int ans = 0;
	while(idx > 0){
		ans += BIT2[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}
void updateQuery2(int idx,int diff){
	for(;idx<=N;idx += (idx & (-idx))){
		BIT2[idx] += diff;
	}
}
int ansQuery3(int idx){
	int ans = 0;
	while(idx > 0){
		ans += BIT3[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}
void updateQuery3(int idx,int diff){
	for(;idx<=N;idx += (idx & (-idx))){
		BIT3[idx] += diff;
	}
}
int ansQuery4(int idx){
	int ans = 0;
	while(idx > 0){
		ans += BIT4[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}
void updateQuery4(int idx,int diff){
	for(;idx<=N;idx += (idx & (-idx))){
		BIT4[idx] += diff;
	}
}
void solveQuestion(){
	int n,q,p;
	cin >> n >> q >> p;
	P = p;
	N = n;
	BIT.resize(n+1);
	fill(BIT.begin(),BIT.end(),0);

	BIT2.resize(n+1);
	fill(BIT2.begin(),BIT2.end(),0);

	BIT3.resize(n+1);
	fill(BIT3.begin(),BIT3.end(),0);

	BIT4.resize(n+1);
	fill(BIT4.begin(),BIT4.end(),0);


	vi arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	vi vals(n+1);
	vi vals2(n+1);
	vi vals3(n+1);
	vi vals4(n+1);
	for(int i=1;i<=n;i++){
		vals[i] = value(arr[i] - arr[i]%P);
		vals2[i] = value(power(arr[i],2) - power(arr[i]%P,2));
		vals3[i] = value(power(arr[i],3) - power(arr[i]%P,3));
		vals4[i] = value(power(arr[i],4) - power(arr[i]%P,4));
	}
	for(int i=1;i<=n;i++){
		updateQuery(i,vals[i]);
		updateQuery2(i,vals2[i]);
		updateQuery3(i,vals3[i]);
		updateQuery4(i,vals4[i]);
	}
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int pos,val;
			cin >> pos >> val;

			int oldValArr = arr[pos];
			int newValArr = val;

			arr[pos] = val;

			int oldVal = value(oldValArr - oldValArr%P);
			int newVal = value(val - val%P);
			vals[pos] = newVal;
			updateQuery(pos,newVal-oldVal);


			int oldVal2 = value(power(oldValArr,2) - power(oldValArr%P,2));
			int newVal2 = value(power(val,2) - power(val%P,2));
			vals2[pos] = newVal2;
			updateQuery2(pos,newVal2-oldVal2);

			int oldVal3 = value(power(oldValArr,3) - power(oldValArr%P,3));
			int newVal3 = value(power(val,3) - power(val%P,3));
			vals3[pos] = newVal3;
			updateQuery3(pos,newVal3-oldVal3);


			int oldVal4 = value(power(oldValArr,4) - power(oldValArr%P,4));
			int newVal4 = value(power(val,4) - power(val%P,4));
			vals4[pos] = newVal4;
			updateQuery4(pos,newVal4-oldVal4);
		}else{
			int s,left,right;
			cin >> s >> left >> right; 
			int sum = 0;
			if(s == 1){
				sum += ansQuery(right) - ansQuery(left-1);
			}else if(s == 2){
				sum += ansQuery2(right) - ansQuery2(left-1);
			}else if(s == 3){
				sum += ansQuery3(right) - ansQuery3(left-1);
			}else{
				sum += ansQuery4(right) - ansQuery4(left-1);
			}
			cout<<sum<<" ";
		}
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