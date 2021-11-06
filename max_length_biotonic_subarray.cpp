#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> input;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            input.push_back(temp);
        }
        vector<int> biotonic(n,0);
        biotonic[0] = 1;
        for(int i=1;i<n;++i){
            if(input[i]>=input[i-1]){
                biotonic[i] = biotonic[i-1]+1;
            }
            else{
                biotonic[i]=1;
            }
        }
        vector<int> decreasing(n,0);
        decreasing[n-1] = 1;
        for(int i=n-2;i>=0;--i){
            if(input[i]>=input[i+1]){
                decreasing[i] = decreasing[i+1] + 1;
            }
            else{
                decreasing[i] = 1;
            }
        }
        int maximum = 1;
        for(int i=0;i<n;i++){
            biotonic[i] = biotonic[i] + decreasing[i] - 1;
            maximum = max(maximum,biotonic[i]);
        }
        cout<<maximum<<endl;
    }
}
