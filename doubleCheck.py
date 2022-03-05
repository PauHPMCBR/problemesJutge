x = input().lower()
for i in range(25,-1,-1):
	c = chr(97+i)
	print(c, "=", x.count(c))