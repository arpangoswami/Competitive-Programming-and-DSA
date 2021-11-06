#include<bits/stdc++.h>
using namespace std;
void change_multiples(bool *sieve,int size_arr,int n){
    int i=n*n;
    while(i<=size_arr){
        sieve[i] = false;
        i+=n;
    }
}
int main(void){
    int n;
    cin>>n;
    bool *sieve = new bool[n+1]();
    for(int i=2;i<=n;i++){
        sieve[i] = true;
    }
    for(int i=2;i<=int(sqrt(double(n)));i++){
        if(sieve[i]==true){
            change_multiples(sieve,n,i);
        }
    }
    int coun=0;
    for(int i=2;i<=n;i++){
        if(sieve[i] == true){
            coun++;
        }
        if(coun == n)
    }
    cout<<coun<<endl;
}
