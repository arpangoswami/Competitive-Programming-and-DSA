/*
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/little-monk-and-virat/
Little Monk and Virat
Attempted by: 838/Accuracy: 63%/Maximum Score: 30/
 7 Votes
Tag(s): Easy-Medium, Heap, Priority queue, Queue, easy-medium
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Little Monk also met who he thinks is the new God of Indian cricket: Virat Kohli. Now Monk is extremely fond of Kohli -- not just as a T20 player, but a player in all formats. He loves the statistics involved in Kohli's career.

Little Monk knows that Kohli has played N matches in all three formats of his career, ODI, T20 and Test Cricket. He wants to show-off his knowledge about Kohli's career so he decides to answer Q questions asked by Kohli. Kohli gives the Monk three different arrays with N numbers each denoting the runs in the ith ODI match, ith Test Match and ith T-20 match respectively.

The value of Kohli's ith match would be the sum of his score in the ith T-20 match, ith Test match and ith ODI match. Kohli knows that Monk is extremely quick at finding the k th smallest value of all his innings, so he twists his query a bit. He asks the Monk to delete the kth smallest value once that is answered by the Monk. If Kohli comes up with a number k which is greater than the number of matches remaining in Kohli's career, the Monk should say that the answer is 1

So much complication confuses the Little Monk and he asks for your help!

Input format:
The first line contains an integer N, which denotes the number of matches played by Virat Kohli. The next three lines contain N integers each denoting the number of runs scored in ODI, T20 and Test respectively. The next line contains an integer Q, denoting the number of questions Virat is going to ask. The next Q lines contain an integer K, denoting the Kth smallest value which the Monk has to answer.

Output format:
Print answer to each query in a new line. In case of an invalid query, print -1.
SAMPLE INPUT
5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
3
1
3
11
SAMPLE OUTPUT
3
12
-1

*/

// Write your code here
#include <iostream>
#include <queue>
using namespace std;
int main(int argc,char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    long *sumarr = new long[n]();
    for(int i=0;i<3;i++){
        for(int j = 0;j<n;j++){
            int temp;
            cin>>temp;
            sumarr[j]+=temp;
        }
    }
    int q;
    cin>>q;
    priority_queue<long,vector<long>,greater<long> > pq(sumarr,sumarr+n);
    while(q--){
        int k;
        cin>>k;
        if(pq.size()<k){
            cout<<-1<<endl;
            continue;
        }
        long *arr = new long[k-1];
        for(int i = 0;i<(k-1);i++){
            arr[i] = pq.top();
            pq.pop();
        }
        cout<<pq.top()<<endl;
        pq.pop();
        for(int i=0;i<(k-1);i++){
            pq.push(arr[i]);
        }
        delete []arr;
    }
    delete []sumarr;
    return 0;
}
