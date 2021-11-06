#include <iostream>
using namespace std;

bool sieve[10000001];
int main() {
    sieve[0]=sieve[1]=1;
    for(int i=2;i*i<=10000000;i++)
        if(!sieve[i])
            for(int j=i*i;j<=10000000;j+=i)
                sieve[j]=1;
    int N;
    cin>>N;
    int counter=1;
    while(N && counter<10000000)
    {
        counter++;
        if(!sieve[counter])
            N--;
    }
    cout<<counter;
}
