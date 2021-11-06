/*
https://www.spoj.com/problems/PPATH/
PPATH - Prime Path
#bfs


The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices.
— It is a matter of security to change such things every now and then, to keep the enemy in the dark.
— But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know!
— I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door.
— No, it's not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime!
— I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds.
— Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime.

Now, the minister of finance, who had been eavesdropping, intervened.
— No unnecessary expenditure, please! I happen to know that the price of a digit is one pound.
— Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you?
— In fact, I do. You see, there is this programming contest going on...

Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above.

    1033
    1733     
    3733     
    3739     
    3779
    8779
    8179     
The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step – a new 1 must be purchased.
Input
One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).

Output
One line for each case, either with a number stating the minimal cost or containing the word Impossible.

Example
Input:
3
1033 8179
1373 8017
1033 1033

Output:
6
7
0
*/
#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<string,int> pii;
bool isPrime(int n){
	if(n == 2){
		return true;
	}
	if(n%2 == 0){
		return false;
	}
	for(int i=3;i*i<=n;i+=2){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}
int bfs(string n,string m,unordered_map<string,unordered_set<string>> adj_list){
	if(n == m){
		return 0;
	}
	unordered_map<string,bool> visited;
	visited[n] = true;
	queue<pii> q;
	q.push({n,0});
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		int lvl = top.second;
		string node = top.first;
		for(string x:adj_list[node]){
			if(visited[x]){
				continue;
			}
			q.push({x,lvl+1});
			visited[x] = true;
			if(x == m){
				return lvl+1;
			}
		}
	}
	return -1;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_map<string,unordered_set<string>> adj_list;
	unordered_map<string,unordered_set<string>> helper;
	unordered_set<int> prim;
	unordered_set<string> primes;
	for(int i=1000;i<=9999;++i){
		if(isPrime(i)){
			prim.insert(i);
		}
	}
	for(int x:prim){
		primes.insert(to_string(x));
	}
	for(string x:primes){
		for(int i=0;i<4;i++){
			string temp = x;
			temp[i]='*';
			helper[temp].insert(x);
		}
	}
	for(auto it=helper.begin();it!=helper.end();++it){
		string st = it->first;
		for(string x:helper[st]){
			for(string y:helper[st]){
				if(y!=x){
					adj_list[x].insert(y);
					adj_list[y].insert(x);
				}
			}
		}
	}
	int test;
	cin>>test;
	while(test--){
		string n,m;
		cin>>n>>m;
		cout<<bfs(n,m,adj_list)<<endl;
	}
	return 0;
}