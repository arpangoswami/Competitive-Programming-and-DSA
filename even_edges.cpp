#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        if(m%2==0){
            for(int q=0;q<m;q++){
            int x,y;
            cin>>x>>y;
        }
            cout<<1<<endl;
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else
        {
            int x,y,x1,y1;
            int *freq=new int[n]();
            cin>>x>>y;
            freq[x-1]++;
            freq[y-1]++;
            x1=x-1;
            y1=y-1;
            for(int q=1;q<m;q++){
                cin>>x>>y;
                freq[x-1]++;
                freq[y-1]++;
            }
            int k;
            bool flag=true;
            for(int i=0;i<n;i++){
                if(freq[i]%2!=0){
                    flag=false;
                    k=i;
                    break;
                }
           }
           if(!flag){
            cout<<2<<endl;
           for(int i=0;i<n;i++){
                    if(i!=k && freq[i]!=0){
                        cout<<1<<" ";
                    }
                    else{
                        cout<<2<<" ";
                    }
                }
            cout<<endl;
           }

           if(flag){
                cout<<3<<endl;
                for(int i=0;i<n;i++){
                    if(i==x1){
                        cout<<2<<" ";
                        continue;
                    }
                    else if(i==y1){
                        cout<<3<<" ";
                        continue;
                    }
                    else{
                        cout<<1<<" ";
                    }
                }
                cout<<endl;
           }
           delete []freq;
        }
    }
}
