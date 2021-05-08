import time
line = 0
with open('lel.txt', 'r') as lel:
	lines = lel.readlines()
	lel.close()

for i in lines:
	print(i, end='')
	line += 1
	if line % 9 == 0:
		time.sleep(0.033)
		print('---------')