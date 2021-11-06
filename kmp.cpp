#include<bits/stdc++.h>
using namespace std;
int *getLPS(string pattern){
    int length = pattern.length();
    int *lps = new int [length];
    int i = 1;
    int j = 0;
    lps[0]=0;
    while(i<length){
        if(pattern[i] == pattern[j]){
            lps[i] = ++j;
            i++;
        }else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int findString(string text,string pattern){
    int lenText = text.length();
    int lenPat = pattern.length();
    int i = 0;
    int j = 0;
    int *lps = getLPS(pattern);
    while(i<lenText && j<lenPat){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0)
            {
                    j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    if(j == lenPat){
        return (i - lenPat);
    }
    else{
        return -1;
    }
}
int main(void){
    string str = "Hello I am Shreyashish Sengupta";
    string pat = "Shreyashish";
    cout<<findString(str,pat)<<endl;
}
