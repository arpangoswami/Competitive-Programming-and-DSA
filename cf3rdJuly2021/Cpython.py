MOD = 10**9 + 7
test = int(input())
for _ in range(test):
	n = int(input())
	prevProd = 1
	currProd = 2
	ans = 0
	for i in range(2,20):
		times = (n/prevProd) - (n/currProd)
		ans += (i*times)
		prevProd *= i
		currProd *= (i+1)
	print(ans)
	print(int(ans % MOD))