#include<bits/stdc++.h>
using namespace std;
const unsigned long long sizearr = (1<<64-1);
int *arr = new int[sizearr];
void primes(){
    for(unsigned long long i=3;i<sizearr;i+=2){
        arr[i] = 1;
    }
    arr[1] = 0;
    arr[2] = 1;
    for(unsigned long long i=3;i*i<sizearr;i+=2){
        if(arr[i] == 1){
            for(unsigned long long j=i*i;j<sizearr;j+=i){
                arr[j] = 0;
            }
        }
    }
    /*for(unsigned i=2;i<sizearr;i++){
        arr[i]+=arr[i-1];
    }*/
}
int main(){
    int n;
    cin>>n;
    primes();
    while(n--){
        int left,right;
        if(arr[left]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
    delete []arr;
}
