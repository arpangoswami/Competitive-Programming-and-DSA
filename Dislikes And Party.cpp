#include<bits/stdc++.h>
using namespace std;
int main(void){
    long n;
    cin>>n;
    map<int,set<int> >hitList;
    set<int> appeared;
    set<int> toCheck;
    for(long i=0;i<10;i++){
        long temp;
        cin>>temp;
        appeared.insert(temp);
        toCheck.insert(temp);
        for(int j=1;j<10;j++){
            long x;
            cin>>x;
            hitList[temp].insert(x);
            appeared.insert(x);
        }
    }
    long notHated = n-appeared.size();
    long handshakes = ((notHated)*(notHated-1))/2;
    handshakes+=(appeared.size())*(notHated);
    vector<int> app;
    for(auto it = appeared.begin();it!=(appeared.end());it++){
        app.push_back(*it);
    }
    for(int i=0;i<app.size()-1;i++){
        for(int j=i+1;j<app.size();j++){
            if(toCheck.find(app[i]) == toCheck.end() && toCheck.find(app[j]) == toCheck.end()){
                handshakes++;
            }
            else if(toCheck.find(app[i]) != toCheck.end() && toCheck.find(app[j]) == toCheck.end() && hitList[app[i]].find(app[j]) == hitList[app[i]].end()){
                handshakes++;
            }
            else if(toCheck.find(app[j]) != toCheck.end() && toCheck.find(app[i]) == toCheck.end() && hitList[app[j]].find(app[i]) == hitList[app[j]].end()){
                handshakes++;
            }
            else if(toCheck.find(app[j]) != toCheck.end() && toCheck.find(app[i]) != toCheck.end() && hitList[app[j]].find(app[i]) == hitList[app[j]].end() && hitList[app[i]].find(app[j]) == hitList[app[i]].end()){
                handshakes++;
            }
        }
    }
    cout<<handshakes<<endl;
}
