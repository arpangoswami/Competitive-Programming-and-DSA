#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        int *x_axis = new int[n];
        int *y_axis = new int[m];
        unordered_map<int,int> x;
        unordered_map<int,int> y;
        int x_neg = 0,x_pos = 0;
        int y_neg = 0,y_pos = 0;
        for(int i=0;i<n;i++){
            cin>>x_axis[i];
            x[x_axis[i]]++;
            if(x_axis[i]<0){
                x_neg++;
            }
            if(x_axis[i]>0){
                x_pos++;
            }
        }
        for(int i=0;i<m;i++){
            cin>>y_axis[i];
            y[y_axis[i]]++;
            if(y_axis[i]<0){
                y_neg++;
            }
            if(y_axis[i]>0){
                y_pos++;
            }
        }
        sort(x_axis,x_axis+n);
        sort(y_axis,y_axis+m);
        long long ans = 0;
        if(x[0]!=0){
            ans+=((long)(n-1)*(long)m);
        }
        if(y[0]!=0){
            ans+=((long)(m-1)*(long)n);
        }
        int rem1 = n-x_pos,rem2 = m-y_pos;
        cout<<"x:loop"<<n<<" "<<x_pos<<endl;
        for(int i=0;i<x_neg;i++){
            cout<<"i: "<<i<<endl;
            for(int j=(n-x_pos);j<n;j++){
                cout<<"j: "<<j<<endl;
                cout<<x_axis[i]<<" "<<x_axis[j]<<endl;
                int possible = (int)sqrt((-1)*(x_axis[i])*(x_axis[j]));
                if(possible*possible == (-1)*x_axis[i]*y_axis[j]){
                    cout<<"inside x"<<endl;
                    cout<<x_axis[i]<<" "<<x_axis[j]<<" "<<possible<<endl;
                    ans+=(long)y[possible];
                    cout<<x_axis[i]<<" "<<x_axis[j]<<" "<<-possible<<endl;
                    ans+=(long)y[-possible];
                }
            }
        }
        cout<<"y:loop"<<m<<" "<<y_pos<<endl;
        for(int i=0;i<y_neg;i++){
            cout<<"i: "<<i<<endl;
            for(int j=(m-y_pos);j<m;j++){
                cout<<"j: "<<j<<endl;
                cout<<y_axis[i]<<" "<<y_axis[j]<<endl;
                int possible = (int)sqrt((-1)*(y_axis[i])*(y_axis[j]));
                if(possible*possible == (-1)*y_axis[i]*y_axis[j]){
                    cout<<"inside y"<<endl;
                    cout<<y_axis[i]<<" "<<y_axis[j]<<" "<<possible<<endl;
                    ans+=(long)x[possible];
                    cout<<y_axis[i]<<" "<<y_axis[j]<<" "<<-possible<<endl;
                    ans+=(long)x[-possible];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
