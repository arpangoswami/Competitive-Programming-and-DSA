#include<bits/stdc++.h>
using namespace std;
int main(void){
    long n;
    cin>>n;
    long *weirdPrefix = new long[n];
    for(int i=0;i<n;i++) cin>>weirdPrefix[i];
    long *original = new long[n];
    original[0] = weirdPrefix[0];
    long sum = max(weirdPrefix[0],(long)0);
    for(int i=1;i<n;i++){
        if(weirdPrefix[i]>=0){
            original[i] = weirdPrefix[i]+sum;
            sum+=weirdPrefix[i];
        }
        else{
            original[i] = weirdPrefix[i]+sum;
        }
    }
    for(long i=0;i<n;i++){
        cout<<original[i]<<" ";
    }
    delete []original;
    delete []weirdPrefix;
}
