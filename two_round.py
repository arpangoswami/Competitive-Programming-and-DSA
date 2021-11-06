from math import factorial as fact
n = int(input())
half = n//2
ans = fact(n)//(fact(half) * fact(half) * 2)
ans *= (fact(half-1) * fact(half-1))
print(ans)