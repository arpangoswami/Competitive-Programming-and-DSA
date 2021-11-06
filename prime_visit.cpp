#include<bits/stdc++.h>
using namespace std;
const unsigned sizearr = 1000001;
int arr[sizearr];
void primes(){
    for(unsigned i=3;i<sizearr;i+=2){
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    for(unsigned i=3;i*i<sizearr;i+=2){
        if(arr[i] == 1){
            for(unsigned j=i*i;j<sizearr;j+=i){
                arr[j] = 0;
            }
        }
    }
    for(unsigned i=2;i<sizearr;i++){
        arr[i]+=arr[i-1];
    }
}
int main(){
    int n;
    cin>>n;
    primes();
    while(n--){
        int left,right;
        cin>>left>>right;
        cout<<arr[right] - arr[left-1]<<endl;
    }
    return 0;
}
