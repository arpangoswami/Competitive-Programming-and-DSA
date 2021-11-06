#include<bits/stdc++.h>
using namespace std;
vector<int> arr(1000001,0);
void sumSubseq(const string &s,int idx,int digits,int &sum,set<char> st){
    if(idx == digits){
        int sm = 0;
        int n = st.size()-1;
        for(auto it = st.begin();it!=st.end();it++){
            sm+=(*it-48)*pow(10,n);
            n--;
        }
        sum+=sm;
    }
    sumSubseq(s,idx+1,digits,sum,st);
    st.insert(s[idx]);
    sumSubseq(s,idx+1,digits,sum,st);
}
int sum_of_subsequences(int n){
    int s = 0;
    int digits = ceil(log10(n));
    if(n%10 == 0){
        digits++;
    }
    string ans="";
    int temp = n;
    while(temp>0){
        ans = (char(temp%10+48)) + ans;
        temp/=10;
    }
    set<char> st;
    sumSubseq(ans,0,ans.size(),s,st);
}
void subsequences(){
    for(int i=1;i<=1000000;i++){
        if(sum_of_subsequences(i)%2!=0){
            arr[i] = 1;
        }
    }
    for(int i=2;i<=1000000;i++){
        arr[i]+=arr[i-1];
    }
}
int main(void){
    int queries;
    cin>>queries;
    subsequences();
    while(queries--){
        int k;
        cin>>k;
        if(k<=5){
            cout<<1<<" "<<(2*k-1)<<endl;
        }
        else{
            int i = lower_bound(arr.begin(),arr.end(),k) - arr.begin();
            cout<<i<<endl;
        }
    }
}
