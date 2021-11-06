#include<bits/stdc++.h>
using namespace std;
struct trainer{
    int starting_day;
    int total;
    int sadness;
};
bool compare(trainer A,trainer B){
    if(A.starting_day!=B.starting_day)
        return A.starting_day<B.starting_day;
    else if(B.sadness!=A.sadness)
        return A.sadness>B.sadness;
    return A.total<B.total;
}
bool compsad(trainer A,trainer B){
    return A.sadness<B.sadness;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int number,total_days;
        cin>>number>>total_days;
        long long totalSum = 0,sum = 0;
        trainer *arr = new trainer[number];
        priority_queue <trainer,vector<trainer>,function<bool(trainer,trainer)> > pq(compsad);
        for(int i=0;i<number;i++){
            cin>>arr[i].starting_day>>arr[i].total>>arr[i].sadness;
            totalSum+=(long long)(arr[i].sadness*arr[i].total);
        }
        sort(arr,arr+number,compare);
        int i=0;
        for(int k=1;k<=total_days;k++)
	    {
	        while(i<number && arr[i].starting_day==k)
	        {
	            pq.push(arr[i]);
	            i++;
	        }
	        if(pq.size()==0)
                continue;
	        //cout<<"Before "<<p.top().sadness<<" "<<p.top().lecture<<endl;
	        sum+=pq.top().sadness;
	        trainer a=pq.top();
	        pq.pop();
	        a.total-=1;
	        if(a.total>0)
	        pq.push(a);
	    }

	   cout<<totalSum-sum<<endl;
        delete []arr;
    }
}
