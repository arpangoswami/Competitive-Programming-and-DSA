#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        long m,n,k;
        cin>>m>>n>>k;
        bool **blocks = new bool *[m];
        long **ways = new long *[m];
        for(long i=0;i<m;i++){
            blocks[i] = new bool[n]();
            ways[i] = new long[n]();
        }
        for(long i=0;i<k;i++){
            long temp1,temp2;
            cin>>temp1>>temp2;
            blocks[temp1-1][temp2-1] = true;
        }
        ways[m-1][n-1] = 1;
        long idx = n-2;
        while(idx>=0 && blocks[m-1][idx] == false){
            ways[m-1][idx] = 1;
            idx--;
        }
        idx = m-2;
        while(idx>=0 && blocks[idx][n-1] == false){
            ways[idx][n-1] = 1;
            idx--;
        }
        for(long i=(m-2);i>=0;i--){
            for(long j = (n-2);j>=0;j--){
                if(blocks[i][j] == true){
                    ways[i][j] = 0;
                }
                else{
                    ways[i][j] = (ways[i][j+1]%mod + ways[i+1][j]%mod)%mod;
                }
            }
        }
        cout<<ways[0][0]<<endl;
        for(long i=0;i<m;i++) {
            delete []ways[i];
            delete []blocks[i];
        }
        delete []ways;
        delete []blocks;
    }
}
