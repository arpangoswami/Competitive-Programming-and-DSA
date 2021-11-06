/*
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/description/

Xor and Insert
Attempted by: 907/Accuracy: 88%/Maximum Score: 30/
 14 Votes
Tag(s): Advanced Data Structures, Data Structures, Medium, Trie
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
At the first, you have a set  (it contains a zero). There are three types of query:

- : Add  to the set.
- : For each element like  set  ( means bitwise exclusive OR, More information).
- : Print the minimum of the set.

Input

The first line contains an integer  ().
In the next  lines, queries are given.
.

Output

For each query of the third type, print the answer.


SAMPLE INPUT
10
3
1 7
3
2 4
2 8
2 3
1 10
1 3
3
2 1
SAMPLE OUTPUT
0
0
3
Explanation
The minimum is 0.
The number  added to .
The minimum is still zero.
All of the numbers in  are changed to their xor with .
All of the numbers in  are changed to their xor with .
All of the numbers in  are changed to their xor with .
The number  added to .
The number  added to .
The minimum is now .
All of the numbers in  are changed to their xor with .
Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded when all the testcases pass.
Allowed Languages:	Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8,
JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave,
Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic


This question taught me a lot including how to implement tries without pointers.

Let us deal with the logic required for the question.

---

First, let us answer the following question - Given a trie and an integer X, how to find the minimum value of XOR(X, Y), where Y is some integer from the trie ?

We will go down the trie from the most significant bit to the least.

Suppose we are at the i-th bit.
If X[i] = 1, we will go down the path of the trie which has 1.
If X[i] = 0, we will go down the path which has 0.

If we do this, then the bit at the i-th position will be 0.

If at position i, we do not have a branch to go down X[i], we will go the other way.

---

Now this question is quite similar to this scenario.

Note that we are only asked to answer queries of the third type - to return the minimum of the array. We do not need to 'answer'
print something) queries of the first and second type.

Suppose we insert
A1, A2, A3 and then ask to xor everything with X1, X2, X3.
Then it is the same as Xor-ing with X = XOR(x1, x2, x3).

Finding the minimum element is equivalent to finding the minimum among (A1, A2, A3) after XOR-ing with X.

We have already noted how to do this with a trie.

This is the basic idea. Now let us see in detail how to answer these queries correctly.

---

Let X = XOR(X1, X2, ... , Xn), where X1, X2, ... , Xn are all asked in the second query.

---

Operation 2 - Xor with Xi.

We will not xor every element in the trie with Xi.
Rather, we will just update X = XOR(X, Xi)

---

Operation 3 - Get the minimum

We were supposed to have XOR-ed the entire array so far with X.
So now we will just calculate the minimum value of XOR(X, Y) with the help of the trie.

---

Operation 1 - Insert A

We must not insert A into the trie, but XOR(A, X). This is a very important step. Why ?

Suppose we do this

Insert A1, A2

XOR with X1

Insert A3

XOR with X2

When we are asked the minimum now, we will find out the minimum value in -

{XOR(A1, X1, X2), XOR(A2, X1, X2), XOR(A3, X1, X2)}

But A3 has only been XOR-ed with X2 and not X1.

---

So it is critical that at every moment in time that we insert an element A into the trie, we insert XOR(A, X).
This ensures that when we caluclate the minimum, it will cancel out the previous XORs.

So in this example, our trie will contain

{A1, A2, XOR(A3, X1)}

When we query the minimum value of XOR(X), we will be finding the minimum of

{XOR(A1, X1, X2), XOR(A2, X1, X2), XOR(A3, X2)}

Which is what we want.

Inserting XOR(A, X) will ensure that whenever we do the minimum operation, we do not do any unnecessary XORs on any A.

----

void answer()
{
    const int INSERT = 1, XOR_ALL = 2, FIND_MINIMUM = 3;
    int query_type;
    cin >> query_type;

    switch(query_type)
    {
        case INSERT : int element;
                      cin >> element;
                      element ^= overall_xor;
                      insert(element);
                      break;

        case XOR_ALL : int x;
                       cin >> x;
                       overall_xor ^= x;
                       break;

        case FIND_MINIMUM : cout << get_minimum_xor_with(overall_xor) << "\n";
                            break;

        default : cout << "Invalid Query\n";
    }
}

---

The insert function of the trie -

void insert(int x)
{
    int p = 0;

    for(int bit = 30; bit >= 0; bit--)
    {
        int current_bit = is_bit_set(x, bit);

        if(trie[p][current_bit] == 0)
        {
            trie[p][current_bit] = largest;

            largest++;
        }

        p = trie[p][current_bit];
    }
}

---

The minimum xor with X function of the trie -

int get_minimum_xor_with(int x)
{
    int answer = 0, p = 0;

    for(int bit = 30; bit >= 0; bit--)
    {
        int current_bit = is_bit_set(x, bit);
        int other_bit = !current_bit;

        if(trie[p][current_bit] != 0)
        {
            p = trie[p][current_bit];
        }
        else
        {
            p = trie[p][other_bit];
            answer |= (1 << bit);
        }
    }

    return answer;
}

---

Be careful to insert 0 into the trie in the beginning.

*/
#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    int value;
    trieNode *left;
    trieNode *right;
    trieNode(){
        value = 0;
        left = NULL;
        right = NULL;
    }
};
void addNumber(int n,trieNode *root){
    trieNode *curr = root;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        if(bit == 0){
            if(curr->left == NULL){
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else{
            if(curr->right == NULL){
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
    curr->value = n;
}
int findMinimumXorPair(int n,trieNode *head){
    trieNode *curr = head;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        if(bit == 0){
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        else{
            if(curr->right){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
    }
    return (curr->value ^ n);
}
int main(void){
    int queries;
    cin>>queries;
    int originalMask = 0;
    trieNode *root = new trieNode();
    addNumber(originalMask,root);
    while(queries--){
        int type;
        cin>>type;
        if(type == 1){
            int num;
            cin>>num;
            addNumber(originalMask^num,root);
        }
        else if(type == 2){
            int num;
            cin>>num;
            originalMask^=num;
        }
        else if(type == 3){
            cout<<findMinimumXorPair(originalMask,root)<<endl;
        }
    }
}
