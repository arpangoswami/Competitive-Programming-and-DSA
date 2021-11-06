#include<iostream>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        long n;
        cin>>n;
        if(n == 1){
            cout<<1<<" "<<1<<endl;
            continue;
        }
        long num = (n/2);
        cout<<num<<endl;
        for(long i=1;i<num;i++){
            cout<<2<<" "<<(2*i-1)<<" "<<(2*i)<<endl;
        }
        if(n%2 == 0){
            cout<<2<<" "<<(n-1)<<" "<<(n)<<endl;
        }
        else{
            cout<<3<<" "<<(n-2)<<" "<<(n-1)<<" "<<(n)<<endl;
        }
    }
}
