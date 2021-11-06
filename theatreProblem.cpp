#include<bits/stdc++.h>
using namespace std;
typedef pair<char,int> request;
int calculateCost(string &s,map<request,int> &mp){
    int a[4]={0},cost = 0,ticket = 100;
    a[0] = mp[make_pair(s[0],3)];
    a[1] = mp[make_pair(s[1],6)];
    a[2] = mp[make_pair(s[2],9)];
    a[3] = mp[make_pair(s[3],12)];
    sort(a,a+4,greater<int>());
    for(int i=0;i<4;i++){
        if(a[i]>0){
            cost+=(a[i]*ticket);
            ticket-=25;
        }
        else{
            cost-=100;
        }
    }
    return cost;
}
int main(){
    int test;
    cin>>test;
    int everyday[test];
    for(int x=0;x<test;x++){
        int n;
        cin>>n;
        if(n==0){
            cout<<-400<<endl;
            everyday[x] = -400;
            continue;
        }
        else if(n==1){
            int time;
            char choice;
            cin>>choice>>time;
            cout<<-200<<endl;
            everyday[x] = -200;
        }
        else{
            map<request,int> mp;
            //bool twelve = false,nine = false,three = false,six = false,a = false,b = false,c = false,d = false;
            while(n--){
                request r;
                cin>>r.first>>r.second;
                mp[r]++;
            }
            int max_cost = -400;
            string s = "ABCD";
            for(int i=0;i<24;i++){
                int cost = calculateCost(s,mp);
                if(max_cost<cost){
                    max_cost = cost;
                }
                next_permutation(s.begin(),s.end());
            }
            cout<<max_cost<<endl;
            everyday[x] = max_cost;
        }
    }
    int profit = 0;
    for(int i=0;i<test;i++){
        profit+=everyday[i];
    }
    cout<<profit<<endl;
    return 0;
}
