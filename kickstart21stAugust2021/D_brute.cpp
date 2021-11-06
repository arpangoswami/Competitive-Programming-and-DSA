#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int i=0;i<n;i++){
		arr[i] = (i+1);
	}
	//cout<<endl;
	int sum = 0,chances = 0;
	do{
		chances++;
		sum ++;
		int picked = arr[0];
		for(int i=1;i<n;i++){
			if(arr[i] > picked){
				sum ++;
				picked = arr[i];
			}
		}
	}while(next_permutation(arr.begin(),arr.end()));
	long double sm = (sum * 1.0);
	long double ch = (chances * 1.0);
	cout<<fixed<<setprecision(9)<<(sm/ch)<<endl;
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