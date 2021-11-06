def bitScore(n):
    largest = n%10
    smallest = n%10
    temp = n
    while(temp > 0):
        dig = temp % 10
        largest = max(largest,dig)
        smallest = min(smallest,dig)
        temp //= 10
    return ((largest * 11) + (smallest * 7)) % 100
lst = [int(x) for x in input('').split()]
n = lst[0]
del lst[0]
odd = {}
even = {}
for i in range(n):
    bs = bitScore(lst[i])
    bs //= 10
    if(i%2 == 1):
        odd[bs] = odd.get(bs, 0) + 1
    else:
        even[bs] =  even.get(bs, 0) + 1
ans = 0
#print(odd)
#print(even)
for i in range(1,10):
    num1 = odd.get(i,0)
    num2 = even.get(i,0)
    possible = (num1 * (num1 - 1))//2
    possible += (num2 * (num2 - 1))//2
    ans += min(2,possible)
print(ans)
    