#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N = 2e7 + 1;
int distinctPr[N];
void pre(){
	for(int i=2;i<N;i++){
		if(distinctPr[i] == 0){
			for(int j=i;j<N;j+=i){
				distinctPr[j]++;
			}
		}
	}
}

// c * lcm - d * gcd = x;
// let lcm = l, gcd = g;
// l * g  = a * b;
// c * (a*b)/g - d*g = x;
// c * (a*b)/g = x + d*g;
// c * (a*b)/(g*g) = x/g + d;
// check whether rhs is divisible by c
// (a*b)/(g*g) = 1/c * (x/g + d)
// (a/g * b/g) = 1/c * (x/g + d)
// Now a/g and b/g must be co prime because whatever common factor was there has been included in the gcd
// X * Y = 1/c * (x/g + d)
// We already have the number of distinct primes which are the factor of RHS in distinctPr. Each prime number will have two choices either to go with Y
// or to go with Z.
// hence ans += (1 << distinctPr[RHS])


void solveQuestion(){
	int c,d,x;
	cin >> c >> d >> x;
	int ans = 0;
	auto check = [&](int hcf){
		int lcm = x/hcf + d;
		
		if(lcm % c != 0){
			return;
		}
		lcm /= c;
		ans += (1 << distinctPr[lcm]);
	};
	for(int hcf=1;hcf*hcf<=x;hcf++){
		if(x % hcf == 0){
			check(hcf);
			if(hcf * hcf != x){
				check(x/hcf);
			}
		}
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}