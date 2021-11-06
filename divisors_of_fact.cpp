#include<bits/stdc++.h>
#define modulo 1000000007
using namespace std;
void change_multiples(bool *sieve,int size_arr,int n){
    int i=n*n;
    while(i<=size_arr){
        sieve[i] = false;
        i+=n;
    }
}
int highest_power(int n,int p){
    int expo=1;
    int power=0;
    while((n/int(pow(p,expo)))!=0){
        power+=(n/int(pow(p,expo));
        expo++;
    }
    return expo;
}
int main(void){
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        if(n==0)
        {
            cout<<1<<endl;
            continue;
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
    bool *sieve = new bool[n+1]();
    for(int i=2;i<=n;i++){
        sieve[i] = true;
    }
    for(int i=2;i<=int(sqrt(double(n)));i++){
        if(sieve[i]==true){
            change_multiples(sieve,n,i);
        }
    }
    int divisors=1;
    for(int i=2;i<=n;i++){
        if(sieve[i]==true){
            divisors=(divisors%modulo*(highest_power(n,i)+1)%modulo)%modulo;
        }
    }
    cout<<divisors<<endl;

    }

}
