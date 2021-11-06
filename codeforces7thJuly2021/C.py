scale = 10**6
def solve(c,m,p,v):
	ans = ((p/scale)*solve(c,m,p,v));
	#choose c next
	if(c > 0):
		if(c > v):
			if(m > 0):
				ans += ((c/scale)*solve(c-v,m+(v//2),p+(v//2),v));
			else:
				ans += ((c/scale)*solve(c-v,0,p+v,v));
		else:
			if(m > 0):
				ans += ((c/scale)*solve(0,m+(c//2),p+(c//2),v));
			else:
				ans += ((c/scale)*solve(0,0,p+c,v));
	#choose m next
	if(m > 0):
		if(m > v):
			if(c > 0):
				ans += ((m/scale) * solve(c+(v//2),m-v,p+(v//2),v));
			else:
				ans += ((m/scale) * solve(0,m-v,p+v,v));
		else:
			if(c > 0):
				ans += ((m/scale) * solve(c+(m//2),0,p+(m//2),v));
			else:
				ans += ((m/scale) * solve(0,0,p+m,v));
	#cout<<"ans: "<<ans<<"\n";
	return ans;
t = int(input())
for _ in range(t):
	cd,md,pd,vd = [float(x) for x in input().split()]
	c = math.round(cd*scale)
	m = math.round(md*scale)
	p = math.round(pd*scale)
	v = math.round(vd*scale)
	ans = solve(c,m,p,v);
	print(ans)
