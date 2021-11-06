a, b = [int(x) for x in input().split(' ')]
idx = 0
if(a == b):
    print(0)
else:
    for i in range(63,-1,-1):
        set1 = (a >> i) & 1
        set2 = (b >> i) & 1
        if(set1!=set2):
            idx = i
            break
    print((1<<(idx+1))-1)