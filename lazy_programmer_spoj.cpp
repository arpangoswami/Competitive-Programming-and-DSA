#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
struct task{
	ll ai;
	ll bi;
	ll di;
	task(ll ai,ll bi,ll di){
		this->ai = ai;
		this->bi = bi;
		this->di = di;
	}
	task(): ai(-1),bi(-1),di(-1) {}
	bool operator < (const task &t1){
		return di<t1.di;
	}
};

int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<task> schedules(n);
		priority_queue<pii> pq;
		for(int i=0;i<n;i++){
			cin>>schedules[i].ai>>schedules[i].bi>>schedules[i].di;
		}
		sort(schedules.begin(),schedules.end());
		ld toPay = 0.00;
		ll time = 0;
		for(int i=0;i<n;++i){
			time+= schedules[i].bi;
			pq.push({schedules[i].ai,schedules[i].bi});
			if(time>schedules[i].di){
				while(true){
					pii temp = pq.top();
					pq.pop();
					if(time - temp.second<=schedules[i].di){
						temp.second -= time - schedules[i].di;
						toPay += (double)(time - schedules[i].di)/(double)temp.first;
						time = schedules[i].di;
						pq.push(temp);
						break;
					}else{
						time-=temp.second;
						toPay+=(double)(temp.second)/(double)(temp.first);
					}
				}
			}
		}
		

		cout<<setprecision(2)<<fixed<<toPay<<endl;
	}
	return 0;
}