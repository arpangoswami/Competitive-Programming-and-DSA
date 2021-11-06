#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
const int MAX = 100;
int buff[MAX];
int main(void){
    for(int i = 0;i<MAX;i++){
        buff[i] = i;
    }
    ofstream outfile("bindata.dat",ios::binary);
    outfile.write(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    outfile.close();
    for(int i = 0;i<MAX ; i++ ){
        buff[i] = 0;
    }
    ifstream infile("bindata.dat",ios::binary);
    infile.read(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    infile.close();
    for(int i=0;i<MAX;i++){
        cout<<buff[i]<<"\n";
    }
}
