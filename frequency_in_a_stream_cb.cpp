#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
struct Element{
    int value;
    int freq;
    Element(int val,int fre){
        value = val;
        freq = fre;
    }
};
struct compare{
    bool operator()(const Element& E1, const Element &E2){
        if(E1.freq!=E2.freq)
            return E1.freq>E2.freq;
        return E1.value<E2.value;
    }
};
int main(void){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<Element,vector<Element>,compare>pq;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            mp[temp]++;
            pq.push(Element(temp,mp[temp]));
            /*int j= 0 ;
            vector<Element> el;
            while(j<k && pq.empty() == false){
                Element temporary = pq.top();
                pq.pop();
                el.push_back(temporary);
                j++;
            }
            for(int x=0;x<el.size();x++){
                cout<<el[x].value<<" ";
                pq.push(el[x]);
            }*/
        }
        cout<<endl;
    }
}
