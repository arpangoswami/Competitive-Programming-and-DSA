n = int(input())
arr = [int(x) for x in input().split()]
sum = 0;
for x in arr:
	sum += x
q = int(input())
MOD = (10**9 + 7)
answer = [0] * (q+1)
answer[0] = sum
for i in range(1,q+1):
	answer[i] = 2*answer[i-1]
	answer[i] %= MOD
	print(answer[i])