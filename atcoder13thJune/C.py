def power(a, b):
	ans = 1;
	while(b > 0):
		if(b & 1):
			ans *= a
		a *= a
	return ans
a, b, c = [int(x) for x in input().split(' ')]
val1 = power(a,c)
val2 = power(b,c)
if(val1 > val2):
	print(">")
elif(val1 < val2):
	print("<")
else:
	print("=")
