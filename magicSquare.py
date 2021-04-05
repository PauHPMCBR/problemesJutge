def is_magic(m):
    n = len(m)
    s = 0
    for j in range(n):
    	s += v[0][j]
    for i in range(n):
    	if i == 0:
    		continue
    	provSum = 0
    	for j in range(n):
    		provSum += v[i][j]
    	if provSum != s:
    		return False

    for j in range(n):
    	if j == 0:
    		continue
    	provSum = 0
    	for i in range(n):
    		provSum += v[i][j]
    	if provSum != s:
    		return False

    provSum = 0
    for i in range(n):
    	provSum += v[i][i]
    if provSum != s:
    	return False

    provSum = 0
    for i in range(n):
    	provSum += v[n-i][i]
    if provSum != s:
    	return False
    return True

v = []
estop = False
while not estop:
	s = input().split()
	if '#' in s:
		if is_magic(v):
			print("This is a magic square")
		else:
			print("This is not a magic square")
		estop = True
	else:
		nums = [int(i) for i in s]
		v.append(nums)
	