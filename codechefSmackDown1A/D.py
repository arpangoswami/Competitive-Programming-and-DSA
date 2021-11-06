t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(x) for x in input().split()]
	arr.sort()
	if(n == 2):
		print(0)
	elif(n == 3):
		print(min(arr[1]-arr[0],arr[2] - arr[1]))
	else:
		lAns = 0
		rAns = 0
		for i in range(n-1):
			last = (n-1)//2
			lAns += abs(arr[i]-arr[last])
		for i in range(1,n):
			last = 1 + ((n-1)//2)
			rAns += abs(arr[i] - arr[last])
		ans = min(lAns,rAns)
		left = 1
		right = n-2
		while(left < right):
			leftPart = arr[n-1] - arr[left]
			rightPart = arr[right] - arr[0]
			ans = min(ans,abs(leftPart-rightPart))
			if(leftPart > rightPart):
				left+=1
			else:
				right-=1
		print(ans) 