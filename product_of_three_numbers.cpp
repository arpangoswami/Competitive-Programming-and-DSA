#include<bits/stdc++.h>
using namespace std;
void primeFactorization(int n,map<int,int>&mp)
{
    //
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n/2;
    }
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            mp[i]++;
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
      mp[n]++;
}
int power(int a,int b){
    if(b==0) return 1;
    int smallProd = power(a,b/2);
    if(b&1) return a*smallProd*smallProd;
    return smallProd*smallProd;
}
int main(void){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> mp;
        primeFactorization(n,mp);
        if(mp.size()>=3){
            cout<<"YES"<<endl;
            auto itr = mp.begin();
            int a = power(itr->first,itr->second);
            itr++;
            int b = power(itr->first,itr->second);
            int c = n/(a*b);
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else if(mp.size()==2){
            auto itr = mp.begin();
            auto itr1 = itr;
            itr++;
            if((itr->second + itr1->second)<4){
                cout<<"NO"<<endl;
            }
            else{
                int a = itr->first;
                int b = itr1->first;
                int c = (n/(a*b));
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
        else if(mp.size()==1){
            auto itr = mp.begin();
            if(itr->second<6){
                cout<<"NO"<<endl;
            }
            else{
                int a = itr->first;
                int b = (itr->first)*(itr->first);
                int c = n/(a*b);
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
