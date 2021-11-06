#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const* argv[]){
    while(true){
        int budget,num;
        cin>>budget>>num;
        if(budget == 0 && num == 0){
            break;
        }
        int *costs = new int[num];
        int *fun = new int[num];
        for(int i=0;i<num;++i){
            cin>>costs[i]>>fun[i];
        }
        int **dp = new int*[num+1];
        for(int i=0;i<=num;i++){
            dp[i] = new int[budget+1]();
        }
        for(int i=1;i<=num;i++){
            for(int j=1;j<=budget;j++){
                if(j>=costs[i-1]){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-costs[i-1]]+fun[i-1]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int max_fun = 0,cost_incurred = 0;
        for(int i=0;i<=budget;i++){
            if(dp[num][i]>max_fun){
                max_fun = dp[num][i];
                cost_incurred = i;
            }
        }
        cout<<cost_incurred<<" "<<max_fun<<endl;
        for(int i=0;i<=num;i++){
            delete []dp[i];
        }
        delete []dp;
        delete []fun;
        delete []costs;
    }
    return 0;
}