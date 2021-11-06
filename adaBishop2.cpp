#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--){
        int r0,c0;
        cin>>r0>>c0;
        int moves = 0;
        vector<pair<int,int> >positions;
        if(r0==c0 && r0!=1){
            moves++;
            positions.push_back(make_pair(1,1));
        }
        else if(r0!=c0){
            moves+=2;
            positions.push_back(make_pair((r0+c0)/2,(r0+c0)/2));
            positions.push_back(make_pair(1,1));
        }
        moves+=25;
        positions.push_back(make_pair(2,2));
        positions.push_back(make_pair(1,3));
        positions.push_back(make_pair(3,1));
        positions.push_back(make_pair(2,2));
        positions.push_back(make_pair(3,3));
        positions.push_back(make_pair(1,5));
        positions.push_back(make_pair(5,1));
        positions.push_back(make_pair(3,3));
        positions.push_back(make_pair(4,4));
        positions.push_back(make_pair(1,7));
        positions.push_back(make_pair(7,1));
        positions.push_back(make_pair(4,4));
        positions.push_back(make_pair(5,5));
        positions.push_back(make_pair(2,8));
        positions.push_back(make_pair(8,2));
        positions.push_back(make_pair(5,5));
        positions.push_back(make_pair(6,6));
        positions.push_back(make_pair(4,8));
        positions.push_back(make_pair(8,4));
        positions.push_back(make_pair(6,6));
        positions.push_back(make_pair(7,7));
        positions.push_back(make_pair(6,8));
        positions.push_back(make_pair(8,6));
        positions.push_back(make_pair(7,7));
        positions.push_back(make_pair(8,8));
        cout<<moves<<endl;
        for(int i=0;i<positions.size();i++){
            cout<<positions[i].first<<" "<<positions[i].second<<endl;
        }
    }
    return 0;
}
