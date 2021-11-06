#include <bits/stdc++.h>
using namespace std;

int main() {
    long int mo=1000000007;
    int m,k;
    cin>>m>>k;
    int a[m];
    map<int,int> mp;
    for(int i=0;i<m;++i)
    {
        cin>>a[i];
        if(mp.count(a[i]))
        {
            mp[a[i]]++;
        }
        else
        {
            mp.insert(pair<int,int>(a[i],1));
        }
    }
    int n=mp.size();
    //cout<<n<<endl;
    long long int arr[n],dum[n];
    map<int,int>::iterator itr;
    int i=0;
    for(itr=mp.begin();itr!=mp.end();++itr)
    {
        arr[i]=itr->second;
        dum[i]=arr[i];
        ++i;
    }
    long int ans=1;
    if(k>0)
    {
        for(int i=n-2;i>=0;--i)
        {
            dum[i]=(dum[i]+dum[i+1])%mo;
        }
            /*for(int i=0;i<n;++i)
            {
                cout<<dum[i]<<" ";
            }
            cout<<endl;*/
        ans=1+dum[0];
        //cout<<ans<<endl;
        ans=ans%mo;
        k--;
        n--;
        //cout<<ans<<endl;
        while(k>0 && n>0)
        {
            for(int i=n-1;i>=0;--i)
            {
                dum[i+1]=(dum[i+1]*arr[i])%mo;
            }
            //cout<<n<<endl;
            /*for(int i=0;i<=n;++i)
            {
                cout<<"dum is"<<dum[i]<<" ";
            }*/
            for(int i=0;i<n;++i)
            {
                dum[i]=dum[i+1];
            }
            //cout<<endl;
            for(int i=n-2;i>=0;--i)
            {
                dum[i]=(dum[i]+dum[i+1])%mo;
            }
            /*for(int i=0;i<n;++i)
            {
                cout<<"dum is"<<dum[i]<<endl;
            }*/
            ans+=dum[0];
            ans=ans%mo;
            --n;
            --k;
        }
    }
    cout<<ans<<endl;
    return 0;
}
