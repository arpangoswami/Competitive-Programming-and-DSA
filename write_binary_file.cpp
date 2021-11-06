#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
const char * filename = "BINARY";
int main(void){
    float height[4] = {175.5,153.0,167.25,160.70};
    ofstream outfile;
    outfile.open(filename);
    outfile.write((char *)&height,sizeof(height));
    outfile.close();
    for(int i=0;i<4;i++){
        height[i] = 0;
    }
    ifstream infile;
    infile.open(filename);
    infile.read((char *)&height,4*sizeof(float));
    for(int i=0;i<4;i++){
        //cout.setf(ios::showpoint);
        cout.setf(ios::left,ios::adjustfield);
        //cout.fill('#');
        cout.precision(2);
        cout.width(10);
        cout<<height[i];
    }
    infile.close();
}
