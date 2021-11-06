#include<bits/stdc++.h>
using namespace std;
long countBits(long n)
{
   long count = 0;
   while (n)
   {
        count++;
        n >>= 1;
    }
    return count;
}
long countSetBits(long n)
{
    long count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
bool filter(long n){
    bool flag = false;
    long bit = countBits(n);
    for(long i = n-1;i>=(n-bit);i--){
        if((countSetBits(i)+i) == n){
            flag = true;
            break;
        }
    }
    return flag;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        long n;
        cin>>n;
        //cout<<countBits(n)<<" "<<countSetBits(n)<<endl;
        long c = 0;
        for(long idx = 1;idx<=n;idx++){
            if(filter(idx) == false){
                c++;
            }
        }
        cout<<c<<endl;
    }
}
