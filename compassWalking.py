from math import sqrt,ceil
r,x,y = [double(i) for i in input().split()]
dist = sqrt(x*x + y*y);
print(ceil(dist/r))