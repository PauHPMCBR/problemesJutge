while True:
	s = input()
	l = len(s)//2
	a = s[0:l]
	b = s[(len(s)-1):(len(s)-1-l)]
	a = [chr(ord(i)+1) for i in a]
	b = [chr(ord(i)+1) for i in b]
	a = a[::-1]
	b = b[::-1]
	for j in range(len(a)):
		a[j] = chr(ord(a[j]) + 1)
	for j in range(len(b)):
		b[j] = chr(ord(b[j]) + 1)
	a = ''.join(map(str,a))
	b = ''.join(map(str,b))
	print(a, end = '')
	if len(s)%2 == 1:
		print(chr(ord(s[l]) + 1), end = '')
	print(b)
	