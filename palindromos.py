for i in range(int(input())):
	n = int(input())
	for x in range(1000): n = (n if (str(n) == str(n)[::-1]) else int((n + int(str(n)[::-1]))/2))
	print(n) if str(n) == str(n)[::-1] else print("Que complicado!")