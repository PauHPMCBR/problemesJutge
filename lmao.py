import math
from sys import stdin, stdout

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    return x % m


def main():
	t = int(input())
	for x in range(t):
		n = int(stdin.readline())
		v = list(map(int, stdin.readline().split()))
		zeros = 0
		for i in v:
			if i == 0:
				zeros += 1
		wrong = 0
		for i in range(zeros):
			if v[i] != 0:
				wrong += 1
		p = 0
		q = 1

		sus = n*(n-1)//2
		for i in range(1, wrong+1):
			x = i*i
			p = p*x + sus*q
			q *= x

		gcd = math.gcd(p, q)
		p = p // gcd
		q = q // gcd

		mod = 998244353
		#print(p, q)
		stdout.write(str(p%mod * modinv(q, mod)%mod) + '\n')




if __name__ == "__main__":
	main()