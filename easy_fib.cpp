#include<bits/stdc++.h>
using namespace std;
int highestPowerof2(unsigned int n)
{
    if (n < 1)
        return 0;
    int res = 1;
    for (int i=33; i<8*sizeof(unsigned long long); i++)
    {
        int curr = 1 << i;
        if (curr > n)
           break;
        res = curr;
    }
    return res;
}
int main(void){
    int test;
    int arr[60];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<60;i++)
        arr[i]=(arr[i-2]+arr[i-1])%10;
    cin>>test;
    while(test--){
        unsigned long long n;
        cin>>n;
        if((1<<32)>n)
        {int m=(int)log2(n);
        unsigned long long a=1<<m;
        a=a%60;
        cout<<arr[a-1]<<endl;}
        else{
            int m=highestPowerof2(n);
            m=m%60;
            cout<<arr[m-1]<<endl;
        }
    }
}
