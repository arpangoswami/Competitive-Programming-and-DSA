def solve():
	n = int(input())
	lst = [int(x) for x in input().split()]
	sm = sum(lst)
	mx = max(lst)
	mx2 = (sm - mx)/(n-1)
	print(mx + mx2)
test = int(input())
for _ in range(test):
	solve()