def bitwiseOR(arr):
    result = set()
    prefix = {0}
    for x in arr:
        prefix = {x | y for y in prefix} | {x}
        result|=prefix
    return len(result)
test = int(input())
for _ in range(test):
    n = int(input())
    lst = [int(x) for x in input().split()]
    total = (n*(n+1))/2
    ans = bitwiseOR(lst)
    if(ans == total):
        print('YES')
    else:
        print('NO')
        