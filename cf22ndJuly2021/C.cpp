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
	string s;
	cin >> s;
	int n = 10;
	vector<int> prefAgoodA(11),prefBgoodA(11),prefAgoodB(11),prefBgoodB(11);
	for(int i=1;i<=10;i++){
		prefAgoodA[i] = prefAgoodA[i-1];
		prefBgoodA[i] = prefBgoodA[i-1];
		prefAgoodB[i] = prefAgoodB[i-1];
		prefBgoodB[i] = prefBgoodB[i-1];
		if(i%2 == 1){
			if(s[i-1] == '1'){
				prefAgoodB[i]++;
				prefAgoodA[i]++;
			}else if(s[i-1] == '0'){
				prefAgoodA[i]++;
			}
		}else{
			if(s[i-1] == '0'){
				prefBgoodA[i]++;
				prefBgoodB[i]++;
			}else if(s[i-1] == '?'){
				prefBgoodB[i]++;
			}
		}
	}
	for(int i=6;i<=10;i++){
		int aShots = (i+1)/2,bShots = i/2;
		int aScoreGoodA = prefAgoodA[i],bScoreGoodA = prefBgoodA[i];
		if(aScoreGoodA + (5-aShots) < bScoreGoodA && aScoreGoodA < bScoreGoodA){
			cout<<i<<"\n";
			return;
		}else if(bScoreGoodA + (5-bShots) < aScoreGoodA && bScoreGoodA < aScoreGoodA){
			cout<<i<<"\n";
			return;
		}
		int bScoreGoodB = prefBgoodB[i], aScoreGoodB = prefAgoodB[i];
		if(aScoreGoodB + (5-aShots) < bScoreGoodB && aScoreGoodB < bScoreGoodB){
			cout<<i<<"\n";
			return;
		}else if(bScoreGoodB + (5-bShots) < aScoreGoodB && bScoreGoodB < aScoreGoodB){
			cout<<i<<"\n";
			return;
		}
	}
	cout<<"10\n";
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