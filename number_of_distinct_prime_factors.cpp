#include<bits/stdc++.h>
using namespace std;
void change_multiples(int *sieve_array,int n){
    int i=n;
    while(i<=1000000){
        (sieve_array[i])++;
        i+=n;
    }
}
int main(void){
    int *sieve = new int[1000001]();
    change_multiples(sieve,2);
    for(int i=3;i<=1000000;i+=2){
        if(sieve[i]==0){
            change_multiples(sieve,i);
        }
    }
    int **pre_comp = new int *[10];
    for(int i=0;i<10;i++){
        pre_comp[i] = new int[1000001];
    }
    /*for(int i=0;i<=30;i++){
        cout<<sieve[i]<<" ";
    }*/
    for(int i=0;i<10;i++){
        pre_comp[i][0] = 0;
    }
    for(int i=0;i<10;i++){
        for(int j=1;j<=1000000;j++){
            if(sieve[j]==i+1){
                pre_comp[i][j] = pre_comp[i][j-1]+1;
            }
            else{
                pre_comp[i][j] = pre_comp[i][j-1];
            }
        }
    }
    int test;
    cin>>test;
    while(test--){
        int a,b,n;
        cin>>a>>b>>n;
        if(n==0){
            if(a==1){
                cout<<1<<endl;
                continue;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            cout<<(pre_comp[n-1][b]-pre_comp[n-1][a-1])<<endl;
        }
    }
    delete []sieve;
    for(int i=0;i<10;i++){
        delete []pre_comp[i];
    }
    delete []pre_comp;
}
