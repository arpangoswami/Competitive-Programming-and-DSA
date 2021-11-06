#include <bits/stdc++.h>
using namespace std;
long long unequal_length(int idx,string s,string t){
    long long l = 0;
    while(s[idx]!=t[idx]){
        l++;
        idx++;
    }
    return l;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        string s,r;
        cin>>s>>r;
        int n = (long long)s.size();
        long long start = 0;
        for(int i=0;i<n && s[i]==r[i];i++){
            start++;
        }
        if(start == n){
            cout<<0<<endl;
            continue;
        }
        long long fin = 0;
        for(int i=n-1;i>=0 && s[i]==r[i];i--){
            fin++;
        }
        s = s.substr(start,n-start-fin);
        r = r.substr(start,n-start-fin);
        n = n-start-fin;
        long long mini = n;
        long long k = 0;
        long long length = 0;
        int i = 0;
        while(i<n){
            if(s[i]!=r[i]){
                k++;
                long long len = unequal_length(i,s,r);
                mini = min(mini,k*(n-i+length));
                i+=len;
                length+=len;
            }
            else{
                i++;
            }
        }
        cout<<mini<<endl;
    }
    return 0;
}
/*
abcdeabcdeabcdeabcdeabcde
eabcdabcdeabceabcdeeabcde*/
