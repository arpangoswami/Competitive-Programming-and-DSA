from math import sqrt,ceil,floor,trunc
def calDist(xC,yC,x,y):
	return (xC-x)*(xC-x) + (yC-y)*(yC-y)
def highBinSearch(x,y,y_co,r):
	low = ceil(x)
	high = low+r
	dist = calDist(x,y,low,y_co)
	if(dist > r*r):
		return -1e9
	ans = low
	while(low <= high):
		mid = (low + high)//2;
		if(calDist(x,y,mid,y_co) <= r*r):
			ans = mid;
			low = mid+1;
		else:
			high = mid-1;
	return ans
def lowBinSearch(x,y,y_co,r):
	high = floor(x)
	low = high-r
	dist = calDist(x,y,high,y_co)
	if(dist > r*r):
		return -1e9
	ans = high
	while(low <= high):
		mid = int(low + high)//2;
		if(calDist(x,y,mid,y_co) <= r*r):
			ans = mid;
			high = mid-1;
		else:
			low = mid+1;
	return ans		
x,y,r = input().split()
x = float(x)
y = float(y)
r = float(r)
topY = int(y+r)
botY = int(y-r)
ans = 0
for i in range(botY,topY+1):
	rightX = highBinSearch(x,y,i,r)
	leftX = lowBinSearch(x,y,i,r)
	if(rightX!=(-1e9) and leftX!=(-1e9)):
		ans+=(rightX - leftX + 1)
	elif(rightX == (-1e9) and leftX!=(-1e9)):
		ans += (floor(x) - leftX + 1)
	elif(rightX != (-1e9) and (leftX) == (-1e9)):
		ans += (rightX - ceil(x) + 1)
print(int(ans))