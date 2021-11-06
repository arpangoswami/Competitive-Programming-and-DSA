#wrong 
from math import log2, ceil
original = ["c","o","d","e","f","o","r","c","e","s"]
k = int(input())
extra = (ceil)(log2(k))
atleast = extra//10;
front = extra%10
atleast+=1
lst = []
for i in range(front):
    num = atleast+1
    for j in range(num):
        lst.append(original[i])
for i in range(front,len(original)):
    num = atleast
    for j in range(num):
        lst.append(original[i])
s = ""
s = s.join(lst)
print(s)