def isPrime(x):
	if x<2:
		return False
	i = 2
	while i*i<=x:
		if x%i == 0:
			return False
		i += 1
	return True

def getPrimes(n):
	primes = []
	for i in range(n//2+1, n):
		if isPrime(i):
			primes.append(i)
	return primes

n=4
a = [1 for x in range(n)]
b = [1 for x in range(n)]
v = [[-1 for x in range(n)] for y in range(n)]
s = {n*n+1}

def check(x):
	if a[x]==b[x]:
		return True
	return False


def sol(x,y,f):
	if x==n and y==n:
		return True
	if y==n:
		return sol(x+1, x, not f)
	if x==n:
		if not check(y):
			return False
		return sol(y+1, y+1, not f)
	if x==y:
		v[x][y] = 1
		if f:
			return sol(x, y+1, f)
		else:
			return sol(x+1, y, f)
	for i in range(n*n+1):
		if i == 0:
			continue
		if i in primes:
			continue
		if not i in s:
			s.add(i)
			v[x][y] = i
			a[x] *= i
			b[y] *= i
			if f:
				if sol(x, y+1, f):
					return True
			else:
				if sol(x+1, y, f):
					return True
			v[x][y] = -1
			a[x] = a[x] // i
			b[y] = b[y] // i
			s.discard(i)
	return False



primes = getPrimes(n*n)
if sol(0, 0, True):
	for i in v:
		print(i)
else:
	print("no sol")