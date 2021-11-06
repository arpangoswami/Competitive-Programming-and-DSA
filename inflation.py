def check(lst,inc,n,per):
	original = lst[0]
	original += inc
	for i in range(1,n):
		v = (lst[i])/original
		if(v > per):
			return False
		original += lst[i];
	return True
t = int(input())
for _ in range(t):
	n, k = [int(x) for x in input().split()]
	lst = [int(x) for x in input().split()]
	low = 0
	high = 10**12
	ans = high
	k/=100
	while(low <= high):
		mid = (low + high)//2
		if(check(lst,mid,n,k)):
			ans = mid
			high = mid-1
		else:
			low = mid+1
	print(ans)
