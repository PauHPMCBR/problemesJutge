while(True):
	n = input()
	res = 0
	for x in range(len(n)):
		if n[x]==n[(x+1)%len(n)]:
			res+= ((int(n[x])+1)%2)*(int(n[x])-1)+int(n[x])
	print(res)