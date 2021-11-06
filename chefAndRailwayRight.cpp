#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        int *x_axes = new int[n],*y_axes = new int[m],x_neg = 0,x_pos = 0,y_neg = 0,y_pos = 0;
        unordered_map<int,int> x;
        unordered_map<int,int> y;
        for(int i=0;i<n;i++){
            cin>>x_axes[i];
            x[x_axes[i]]++;;
            if(x_axes[i]>0){
                x_pos++;
            }
            else if(x_axes[i]<0){
                x_neg++;
            }
        }
        for(int i=0;i<m;i++){
            cin>>y_axes[i];
            y[y_axes[i]]++;
            if(y_axes[i]>0){
                y_pos++;
            }
            else if(y_axes[i]<0){
                y_neg++;
            }
        }
        long ans = 0;
        if(x[0]!=0){
            ans+=((long)(n-1)*(long)(m));
        }
        if(y[0]!=0){
            ans+=((long)(m-1)*(long)(n));
        }
        sort(x_axes,x_axes+n);
        sort(y_axes,y_axes+m);
        for(int i=0;i<x_neg;i++){
            for(int j=(n-x_pos);j<n;j++){
                int possible = (int)sqrt(-1*x_axes[i]*x_axes[j]);
                if(possible*possible == (-1*x_axes[i]*x_axes[j])){
                    if(y[possible]!=0){
                            ans++;
                        //ans+=(long)y[possible];
                    }
                    if(y[-possible]!=0){
                        ans++;
                        //ans+=(long)y[-possible];
                    }
                }
            }
        }
        for(int i=0;i<y_neg;i++){
            for(int j=(m-y_pos);j<m;j++){
                int possible = (int)sqrt(-1*y_axes[i]*y_axes[j]);
                if(possible*possible == (-1*y_axes[i]*y_axes[j])){
                    if(x[possible]!=0){
                            ans++;
                        //ans+=(long)x[possible];
                    }
                    if(x[-possible]!=0){
                        ans++;
                        //ans+=(long)x[-possible];
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
