#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
    int test;
    while(test--){
        int c1,c2,c3,c4;
        cin>>c1>>c2>>c3>>c4;
        int n,m;
        cin>>n>>m;
        vector<int> rick(n);
        vector<int> cab(m);
        for(int i=0;i<n;i++){
            cin>>rick[i];
        }
        for(int i=0;i<m;i++){
            cin>>cab[i];
        }
        cout<<5<<endl;
        int rick_cost = 0;
        int cab_cost = 0;
        for(int i=0;i<n;i++){
            rick_cost+=min(c1*rick[i],c2);
        }
        rick_cost = min(c3,rick_cost);
        for(int i=0;i<m;i++){
            cab_cost+=min(c1*cab[i],c2);
        }
        cab_cost = min(c3,cab_cost);
        int total_cost = rick_cost+cab_cost;
        total_cost = min(c4,total_cost);
        cout<<total_cost<<endl;

    }
}
