#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        long long n,m;
        cin>>n>>m;
        if(m<(n-1) || m>((n)*(n+1))/2)
            cout<<-1<<endl;
        else if(m==(n-1))
            cout<<1<<endl;
        else if(m>(n-1) && m<=((2*n)-1))
            cout<<2<<endl;
        else{
            int ans;
            long long *sum=new long long[n];
            sum[0]=n-1;
            sum[1]=2*n-1;
            for(int i=2;i<n;i++){
                sum[i]=sum[i-1]+(n-i);
                if(m==sum[i])
                {
                    ans=i+1;
                    break;
                }
                else if(m<sum[i] && m>sum[i-1]){
                    ans=i;
                    break;
                }
                cout<<ans<<endl;
            }
            delete [] sum;
        }
    }
}
