#include<bits/stdc++.h>
using namespace std;
//typedef pair<char,int> request;
int calculateCost(string &s,int *arr){
    int a[4]={0},cost = 0,ticket = 100;
    a[0] = arr[(s[0]*3-195)];
    a[1] = arr[(s[1]*6-195)];
    a[2] = arr[(s[2]*9-195)];
    a[3] = arr[(s[3]*12-195)];
    sort(a,a+4);
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
    while(test--){
        int n;
        cin>>n;
        if(n==0){
            cout<<-400<<endl;
            continue;
        }
        else if(n==1){
            int time;
            char choice;
            cin>>choice>>time;
            cout<<-200<<endl;
        }
        else{
            int arr[621]={0};
            while(n--){
                int time;
                char choice;
                cin>>choice>>time;
                arr[(choice*time)-195]++;
            }
            int max_cost = -400;
            string s = "ABCD";
            for(int i=0;i<24;i++){
                int cost = calculateCost(s,arr);
                max_cost = max(max_cost,cost);
                next_permutation(s.begin(),s.end());
            }
            cout<<max_cost<<endl;
        }
    }
    return 0;
}
