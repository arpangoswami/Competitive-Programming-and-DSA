test = int(input())
for _ in range(test):
    a = int(input())
    highestPower = 0
    for i in range(64):
        if((1<<i) <= a):
            highestPower = i
        else:
            break
    lst = [0]*(highestPower+1)
    for i in range(highestPower+1):
        lst[i] = a//(1<<i)
    for i in range(highestPower):
        lst[i] = lst[i] - lst[i+1]
    ans = 0
    for i in range(highestPower + 1):
        ans = ans + (1+i)*lst[i]
    print(ans)