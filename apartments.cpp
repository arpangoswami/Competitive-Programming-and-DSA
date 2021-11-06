/*
Apartments
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input

The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.

The next line contains n integers a1,a2,…,an: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.

The last line contains m integers b1,b2,…,bm: the size of each apartment.

Output

Print one integer: the number of applicants who will get an apartment.

Constraints
1≤n,m≤2⋅105
0≤k≤109
1≤ai,bi≤109
Example

Input:
4 3 5
60 45 80 60
30 60 75

Output:
2
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k,x;
	cin >> n >> k >> x;
	vector<int> arr(n);
	vector<int> req(k);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<k;i++){
		cin >> req[i];
	}
	sort(arr.begin(),arr.end());
	sort(req.begin(),req.end());
	int cnt = 0;
	int i=0,j=0;
	while(i<n && j<k){
		if(arr[i] > req[j] + x){
			j++;
		}else if(arr[i] < req[j] - x){
			i++;
		}else{
			cnt++;
			i++;
			j++;
		}
	}
	cout<<cnt<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}