import math

def isPrime(n):
	if n < 2:
		return False
	if n == 2:
		return True
	if n%2 == 0:
		return False
	for i in range(3, int(math.sqrt(n)+1), 2):
		if n%i == 0:
			return False
	return True

n = int(1e7)
ans = 0
for i in range(n):
	if isPrime(i):
		ans += 1

print(ans)