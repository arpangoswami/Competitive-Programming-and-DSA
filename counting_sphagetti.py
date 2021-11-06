test = int(input());
for _ in range(test):
	x,y = [int(x) for x in input().split()];
	print((y*(y+1))//2)