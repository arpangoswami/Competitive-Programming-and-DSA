n = int(input())
s = input()
t = input()
freqA = [0] * 10
freqB = [0] * 10
for i in range(4):
	v1 = int(s[i])
	v2 = int(t[i])
	freqA[v1] += 1
	freqB[v2] += 1
num = 0
den = 0
for i in range(1,10):
	if(freqA[i] + freqB[i] + 1 > n):
		continue
	for j in range(1,10):
		if(freqB[j] + freqA[j] + 1 > n):
			continue
		if(i == j and (freqA[i] + freqB[i] + 2) > n):
			continue
		freqA[i] += 1
		freqB[j] += 1
		scoreA = 0
		scoreB = 0
		for k in range(1,10):
			scoreA += (k * 10 ** freqA[k])
			scoreB += (k * 10 ** freqB[k])
		freqA[i] -= 1
		freqB[j] -= 1
		if(i == j):
			rem = (n - freqA[i] - freqB[j])
			if(scoreA > scoreB):
				num += (rem * (rem-1))
			den += (rem * (rem-1))
		else:
			remI = (n - freqA[i] - freqB[i])
			remJ = (n - freqA[j] - freqB[j])
			if(scoreA > scoreB):
				num += (remI * remJ)
			den += (remI * remJ)


print(num/den)