#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a,b,c,d,e;
        cin>>a;
        //cout<<pow(10,n)<<endl;
        long long pair_wise_sum = (pow(10,n));
        //cout<<"pairwise sum = "<<pair_wise_sum<<endl;
        long long sum = (pair_wise_sum*2)+a;
        cout<<sum<<endl;
        cin>>b;
        c = pair_wise_sum - b;
        cout<<c<<endl;
        cin>>d;
        e = pair_wise_sum - d;
        cout<<e<<endl;
        int correct;
        cin>>correct;
        /*if(a+b+c+d+e == sum){
            correct = 1;
            continue;
        }
        else{
            correct = -1;
            break;
        }*/
        if(correct == -1){
            break;
        }
    }
}
