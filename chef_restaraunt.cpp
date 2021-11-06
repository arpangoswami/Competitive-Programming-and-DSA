#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>intervals;
        for(int i=0;i<n;i++){
            int open,close;
            cin>>open>>close;
            intervals.push_back(make_pair(open,close));
        }
        sort(intervals.begin(),intervals.end());
        while(m--){
            int timing;
            cin>>timing;
            int position = lower_bound(intervals.begin(),intervals.end(),make_pair(timing,0))-intervals.begin();
            if(position == 0){
                cout<<intervals[0].first-timing<<endl;
            }else{
                int ans = -1;
                if(intervals[position-1].second>timing){
                    ans = 0;
                }
                else if(position<n){
                    ans = intervals[position].first-timing;
                }
                cout<<ans<<endl;
            }
        }
    }
}
