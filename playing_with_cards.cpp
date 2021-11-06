#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i == 0){
			return false;
		}
	}
	return true;
}
int main() {
	int n,q;
	cin>>n>>q;
	vector<stack<int>> B(q);
	stack<int> A;
	vector<int> primes;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		A.push(x);
	}
    primes.push_back(1);
	for(int i=2;i<=1e4;i++){
		if(checkPrime(i)){
			primes.push_back(i);
		}
	}
	for(int i=1;i<=q && A.size();i++){
		stack<int> temp;
		while(!A.empty()){
			int x = A.top();
			A.pop();
			if(x%primes[i] == 0){
				B[i-1].push(x);
			}else{
				temp.push(x);
			}
		}
		swap(temp,A);
	}
	for(int i=1;i<=q;i++){
		while(!B[i-1].empty()){
			int x = B[i-1].top();
			B[i-1].pop();
			cout<<x<<endl;
		}
	}
	while(!A.empty()){
		int x = A.top();
		A.pop();
		cout<<x<<endl;
	}
	return 0;
}