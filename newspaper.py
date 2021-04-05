n = int(input())
stop = True
counter = 0
while stop:
	s = input()
	if s[-1] == '#':
		stop = False
		s = s[:-1]
	s = s.split()
	while len(s) > 0:
		if counter+len(s[0]) >= n:
			print()
			counter = 0
		print(s[0] if counter == 0 else ' '+s[0], end = '')
		counter += len(s[0])+1
		s.pop(0)
	if counter != 0:
		counter = 0
		print()