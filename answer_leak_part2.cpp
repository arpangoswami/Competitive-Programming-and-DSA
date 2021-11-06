#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct kthSheet{
    int idx;
    int incorrect_till_now;
    kthSheet(int i,int n){
        idx = i;
        incorrect_till_now = n;
    }
};
struct myCmp{
    bool operator()(kthSheet &k1,kthSheet &k2){
        return k1.incorrect_till_now<k2.incorrect_till_now;
    }
};
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int> >answer_sheet;
        for(int i=0;i<n;i++){
            vector<int> temp(k);
            for(int j=0;j<k;j++){
                cin>>temp[j];
            }
            answer_sheet.push_back(temp);
        }
        priority_queue<kthSheet, vector<kthSheet>,myCmp > pq;
        for(int i=0;i<k;i++){
            kthSheet k1 = kthSheet(i,n);
            pq.push(k1);
        }
        vector<int> chefs_answers;
        for(int i=0;i<n;i++){
            kthSheet k = pq.top();
            pq.pop();
            chefs_answers.push_back(answer_sheet[i][k.idx]);
            if(k.incorrect_till_now>1){
                kthSheet k2 = kthSheet(k.idx,k.incorrect_till_now-1);
                pq.push(k2);
            }
        }
        for(int i=0;i<n;i++){
            cout<<chefs_answers[i]<<" ";
        }
        cout<<"\n";
    }
}
