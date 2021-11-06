#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long commonBitsCount(long a,long b){
    long c = 0;
    /*unordered_set<int> s;
    for(int i=0;i<32;i++){
        if(a&(1<<i)){
            s.insert(i);
        }
    }
    for(int i=0;i<32;i++){
        if(b&(1<<i)){
            if(s.find(i)!=s.end()){
                c++;
            }
        }
    }*/
    if(a&1 && b&1){
        c++;
        a>>=1;
        b>>=1;
    }
    long i=1;
    while(a>0 && b>0){
        if(a&1 && b&1){
            c++;
        }
        a>>=1;
        b>>=1;
    }
    return c;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--){
        long n;
        cin>>n;
        long *arr = new long[n]();
        long *dp = new long[n]();
        bool flag = false;
        for(long i=0;i<n;i++) cin>>arr[i];
        for(long i=0;i<(n-1);i++){
            if(arr[i]&arr[i+1]!=arr[i]){
                cout<<0<<endl;
                flag = true;
                break;
            }
        }
        dp[0] = 1;
        //if(arr[n-1] == 0){
          //  cout<<0<<endl;
            //continue;
        //}
        if(!flag){
            for(long i=1;i<n;i++){
                long bit = commonBitsCount(arr[i],arr[i-1]);
                dp[i] = ((dp[i-1]%mod) * (((long)(1<<bit))%mod))%mod;
            }
            cout<<dp[n-1]%mod<<endl;
        }
        delete []arr;
        delete []dp;
    }
}
