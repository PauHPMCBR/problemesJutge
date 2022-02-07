from random import randint as rng 

cases = 0
sol = 0
for i in range(1000,10000):
	s = str(i)
	if "22" in s:
		sol += 1

print(sol)
print(cases)