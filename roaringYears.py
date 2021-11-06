test = int(input())
MAX_LIMIT = 10000000001000000001
lst = []
def addNumToList(startNum,consNum):
	local = []
	lastNum = startNum+consNum
	for i in range(startNum,startNum+consNum):
		local.append(str(i))
	s = ''.join(local)
	#print(s)
	num = int(s)
	if(num > MAX_LIMIT):
		return False
	lst.append(num)
	return True
for consNum in range(2,15):
	for startNum in range(1,1000000000):
		flag = addNumToList(startNum,consNum)
		if(flag == False):
			break
lst.sort()
print(lst)
for _ in range(1,test+1):
	print('Case ','#',_,': ',sep='',end='')
	year = int(input())
	print(0)