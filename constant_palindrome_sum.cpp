#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        vector<pii> prs(n/2);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        for(int i=0;i<(n/2);i++){
            int x = nums[i],y = nums[n-i-1];
            if(x>y){
                prs[i] = {y,x};
            }
            else{
                prs[i] = {x,y};
            }
        }
        vector<int> onechange(2*k+2,0);
        unordered_map<int,int> mp;
        for(int i=0;i<n/2;i++){
            int lrange = prs[i].first+1;
            int rrange = prs[i].second+k;
            onechange[lrange]++;
            onechange[rrange+1]--;
            mp[prs[i].first+prs[i].second]++;
        }
        for(int i=2;i<=2*k;i++){
            onechange[i]+=onechange[i-1];
            //cout<<onechange[i]<<" ";
        }
        //cout<<endl;
        int mini = n;
        for(int i=2;i<=2*k;i++){
            int cnt0 = mp[i];
            int cnt1 = onechange[i]-cnt0;
            int cnt2 = n/2 - cnt1 - cnt0;
            int cnt = 2*cnt2 + cnt1;
            mini = min(mini,cnt);
        }
        cout<<mini<<endl;
    }
    return 0;
}
