/*
B. Same Parity Summands
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two positive integers n (1≤n≤109) and k (1≤k≤100). Represent the number n as the sum of k positive integers of the same parity (have the same remainder when divided by 2).

In other words, find a1,a2,…,ak such that all ai>0, n=a1+a2+…+ak and either all ai are even or all ai are odd at the same time.

If such a representation does not exist, then report it.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Next, t test cases are given, one per line.

Each test case is two positive integers n (1≤n≤109) and k (1≤k≤100).

Output
For each test case print:

YES and the required values ai, if the answer exists (if there are several answers, print any of them);
NO if the answer does not exist.
The letters in the words YES and NO can be printed in any case.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){ 	
	int test;
	cin>>test;
	while(test--){
		ll n,k;
		cin>>n>>k;
		if(k>n){
			cout<<"NO"<<endl;
		}
		else if(n%2 == 1){//Odd
			if(k%2 == 0){//Cant be expressed as sum of even terms of same parity
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;//1 + 1 + ... k-1 times.Since k is odd,k-1 is even n - (k - 1) will be odd
				ll sum = k-1;
				for(int i=1;i<=(k-1);i++){
					cout<<1<<" ";
				}
				cout<<(n-sum)<<endl;
			}
		}
		else{
			if((2*(k-1))>=n){
				if(k&1){
					cout<<"NO"<<endl;
				}
				else{
					ll sum = k-1;
					cout<<"YES"<<endl;
					for(int i=1;i<=(k-1);i++){
						cout<<1<<" ";
					}
					cout<<(n-sum)<<endl;
				}
			}
			else{
				cout<<"YES"<<endl;
				ll sum = 2*(k-1);//2 + 2 + 2 ... k-1 times n - sum is even
				for(int i=1;i<=(k-1);i++){
					cout<<2<<" ";
				}
				cout<<(n - sum)<<endl;
			}
		}
	}
	return 0;
}