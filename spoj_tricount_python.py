test = int(input())
max_len = 1000001
lst = [0]*max_len
for i in range(1,max_len):
	lst[i] = i*i
sumTill = 1
for i in range(2,max_len):
	lst[i] += sumTill
	sumTill += (i * (i + 1))//2
for _ in range(test):
	u = int(input())
	print(lst[u])