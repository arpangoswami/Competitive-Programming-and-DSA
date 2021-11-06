from math import factorial
def rank(num,a,b):
	if(num == 1):
		lst = []
		for _ in range(a):
			lst.append('a');
		for _ in range(b):
			lst.append('b');
		return lst
	elif(a == 0):
		lst = []
		for _ in range(b):
			lst.append('b');
		return lst;
	elif(b == 0):
		lst = []
		for _ in range(a):
			lst.append('a');
		return lst;
	aStart = factorial(a+b-1)//(factorial(a-1)*factorial(b));
	if(num > aStart):
		lst = []
		lst.append('b');
		lst2 = rank(num-aStart,a,b-1);
		lst.extend(lst2);
		return lst;
	lst = []
	lst.append('a');
	lst2 = rank(num,a-1,b);
	lst.extend(lst2);
	return lst;
a,b,k = [int(x) for x in input().split()]
lst = rank(k,a,b)
s = ''.join(lst)
print(s)