t = int(input())
for dklg in range(t):
	mobe = input().split()
	n = int(mobe[0])
	m = int(mobe[1])
	k = int(mobe[2])
	v = [[0 for x in range(m)] for y in range(n)]
	suma = 0
	for sdf in range(k):
		mobe = input().split()
		c = mobe[0]
		x = int(mobe[1])
		s = int(mobe[2])
		x -= 1
		if c == 'C':
			for i in range(n):
				suma -= v[i][x]
				v[i][x] = s
				suma += s

		else:
			for i in range(m):
				suma -= v[x][i]
				v[x][i] = s
				suma += s
	print(suma)
