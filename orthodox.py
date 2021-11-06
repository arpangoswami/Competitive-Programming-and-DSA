n = int(input())
lst = [int(x) for x in input().split()]
s = set()
ans = []
for i in range(n):
    val = 0
    for j in range(i,n):
        val = val | lst[j]
        ans.append(val)
print(ans)