from random import randint as rng
MOBE = input().split()
n = int(MOBE[0])
c = int(MOBE[1])
v = int(MOBE[2])
a = 0
for i in range(10000):
	s = 0
	for j in range(n):
		s += rng(1, c)
	if s == v:
		a+=1
print("The probability of getting a "+str(v)+" with "+str(n)+" dice of "+str(c)+" faces is " +str(round(a/100000, 3)))

