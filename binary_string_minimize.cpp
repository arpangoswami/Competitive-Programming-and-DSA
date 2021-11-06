#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        string bin;
        cin>>bin;
        set<int> pos1;
        set<int> pos0;
        for(int i=0;i<n;i++){
            if(bin[i] == '1'){
                pos1.insert(i);
            }
            else{
                pos0.insert(i);
            }
        }

        set <int> :: iterator i=pos1.begin();
        set <int> :: iterator j=pos0.begin();
        while(i!=pos1.end() && j!=pos0.end() && k>0){
            if(*i<*j){
                if((*j)-(*i)<=k){
                    k = k - (*j-*i);
                    swap(bin[*i],bin[*j]);
                    pos1.insert(*j);
                    pos0.insert(*i);
                    i++;
                    j++;
                }
                else{
                    if(bin[*j-k] == '1'){
                        swap(bin[*j-k],bin[*j]);
                        pos1.insert(*j);
                        pos0.insert(*j-k);
                        i++;
                        j++;
                        k=0;
                    }
                    else{
                        int c=0;
                        int q;
                        for(q = *j-k;q<n;q++){
                            if(bin[q] == '1'){
                                break;
                            }
                            c++;
                        }
                        swap(bin[q],bin[*j]);
                        pos0.insert(q);
                        pos1.insert(*j);
                        k=c;
                        j++;
                    }
                }
            }
            else{
                j++;
            }
        }
        cout<<bin<<endl;
    }
}
